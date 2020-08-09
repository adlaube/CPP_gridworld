#include "include/catch.hpp"
#include "array3d.hpp"

TEST_CASE("Test Array3d"){

    Array3d<double> ar1;
    const Array3d<double> ar2(3,3,3);
    REQUIRE_NOTHROW(Array3d<double>(3,3,3));
    REQUIRE_NOTHROW(ar1 = Array3d<double>(3,3,3));
    REQUIRE_THROWS(ar1(2,4,2));
    REQUIRE_THROWS(ar1(2,4,2));
    REQUIRE_THROWS(ar1(2,2,4));
    REQUIRE_NOTHROW(ar1(1,1,1) = 3);
    REQUIRE_NOTHROW(ar1(1,1,1) == 3);
    REQUIRE_NOTHROW(ar2(1,1,1));
    REQUIRE_THROWS(ar1(4,1,1) == 3);
    REQUIRE_THROWS(ar2(4,1,1) == 3);
}