#include "iterative.hpp"
#include "iterativeConstructor.hpp"

static IterativeConstructor monte_carlo_constructor;

void Iterative::evaluatePolicyAtState(STATE_ID state, ACTION_ID selected_action)
{
	double V_current = 0;
	STATE_ID num_of_states = model_.num_of_states;

	for (STATE_ID state_idx = 0; state_idx < num_of_states; state_idx++) {
		double transition_probability;
		transition_probability = model_.state_transition_matrix(
			selected_action, state, state_idx);
		// Bellman equation
		V_current = V_current +
			    transition_probability *
				    (model_.reward_matrix(selected_action,
							  state, state_idx) +
				     model_.discount_rate *
					     value_function_[state_idx]);
	}
	value_function_[state] = V_current;
}

void Iterative::evaluatePolicy(const Policy &policy)
{
	STATE_ID num_of_states = model_.num_of_states;

	for (STATE_ID state_idx = 0; state_idx < num_of_states; state_idx++) {
		ACTION_ID selected_action;
		selected_action = policy.getActionOfState(state_idx);
		evaluatePolicyAtState(state_idx, selected_action);
	}
}

double Iterative::getValueOfState(STATE_ID state) const
{
	return value_function_[state];
}
