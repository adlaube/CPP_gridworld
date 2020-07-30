#include "include/catch.hpp"

#include "array3d.hpp"

TEST_CASE("Test Array3d"){

    REQUIRE_NOTHROW(Array3d<double>(3,3,3));

    Array3d<double> a3d (3,3,3);
    CHECK_THROWS(a3d(4,3,3)); 

    //SECTION("bla") have all the same unaltered inputs      
}