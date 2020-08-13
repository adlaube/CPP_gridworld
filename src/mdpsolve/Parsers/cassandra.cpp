#include "cassandra.hpp"
#include "cassandraConstructor.hpp"

static CassandraConstructor cassandra_constructor;

void Cassandra::parseFile(const std::string &filepath)
{
	std::ifstream inputstream;
	inputstream.open(filepath, std::ios::in);
	if (!inputstream) {
		throw("error opening file");
	}
	parseParams(inputstream);
	model_.checkConsistency();
	model_.setArrays();

	inputstream.clear(); // reset error bits
	inputstream.seekg(0);
	inputstream.exceptions();
	parseData(inputstream);
}

void Cassandra::parseRewardMatrix(std::istringstream &iss)
{
	std::string value;
	ACTION_ID action_idx = DEF_ACTION_UNDEF;
	STATE_ID start_state_idx = DEF_STATE_UNDEF;
	STATE_ID next_state_idx = DEF_STATE_UNDEF;
	std::getline(iss, value, ':');
	if (value == " * ") {
		action_idx = DEF_ACTION_ALL;
	}

	std::getline(iss, value, ':');
	start_state_idx = atoi(value.c_str());
	std::getline(iss, value, ':');
	if (value == " * ") {
		next_state_idx = DEF_STATE_ALL;
	}

	std::getline(
	    iss, value,
	    '*'); // skip observation, we have full observability in a MDP
	std::getline(iss, value);
	if (action_idx == DEF_ACTION_ALL && next_state_idx == DEF_STATE_ALL) {
		for (action_idx = 0; action_idx < model_.num_of_actions;
		     action_idx++) {
			for (next_state_idx = 0;
			     next_state_idx < model_.num_of_states;
			     next_state_idx++) {
				model_.reward_matrix(
				    action_idx, start_state_idx,
				    next_state_idx) = atof(value.c_str());
			}
		}
	}
}

void Cassandra::parseTransitionMatrix(std::ifstream &inputstream,
				      const ACTION_ID action)
{
	std::string value, line;

	for (STATE_ID state_idx = 0; state_idx < model_.num_of_states;
	     state_idx++) {
		std::getline(inputstream, line); // access next line
		std::istringstream iss(line);
		STATE_ID i = 0;
		while (std::getline(iss, value, ' ')) { //&& value){
			model_.state_transition_matrix(action, state_idx, i) =
			    atof(value.c_str());
			i++;
		}
		if (i != model_.num_of_states) {
			throw("invalid transition matrix");
		}
	}
}

// error handling
void Cassandra::parseData(std::ifstream &inputstream)
{
	std::string line;
	std::string value;

	while (std::getline(inputstream, line)) {
		std::istringstream iss(line);

		std::string key;
		std::getline(iss, key, ':');

		if (key[0] != '#') {
			// processes multiple lines
			if (key == "T") {
				std::getline(iss, value,
					     ' '); // skip first blank
				std::getline(iss, value);
				auto result = std::find(
				    model_.action_strings.begin(),
				    model_.action_strings.end(), value);
				if (result == model_.action_strings.end()) {
					throw("invalid action");
				}
				ACTION_ID action =
				    result - model_.action_strings.begin();
				parseTransitionMatrix(inputstream, action);
			}
			// processes one line
			if (key == "R") {
				// call
				parseRewardMatrix(iss);
			}
		}
	}
}

void Cassandra::parseParams(std::ifstream &inputstream)
{
	std::string line;
	std::string value;
	while (std::getline(inputstream, line)) {
		std::istringstream iss(line);
		std::string key;
		std::getline(iss, key, ':');
		if (key[0] != '#') {
			if (key == "discount") {
				std::getline(iss, value);
				model_.discount_rate = std::atof(value.c_str());
			}
			if (key == "values") {
				std::getline(iss, value);
				if (value == " reward") {
					model_.optGoal = OPT_MAXIMIZE;
				} else if (value == " cost") {
					model_.optGoal = OPT_MINIMIZE;
				}
			}
			if (key == "states") {
				std::getline(iss, value);
				model_.num_of_states = std::atoi(value.c_str());
			}
			if (key == "actions") { // count whitespaces and alloc
						// accordingly

				ACTION_ID action_cnt = 0;
				std::getline(iss, value,
					     ' '); // skip first blank
				while (std::getline(iss, value, ' ')) {
					model_.action_strings.push_back(value);
					action_cnt++;
				}
				model_.num_of_actions = action_cnt;
			}
		}
	}
}
