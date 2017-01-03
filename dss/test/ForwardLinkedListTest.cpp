#include <stdexcept>

#include "dss/list/ForwardLinkedList.hpp"
#define CATCH_CONFIG_MAIN
#include "third-party/catch.hpp"

TEST_CASE(
    "ForwardLinkedList can be constructed and has appropriate size",
    "[constructors]")
{
    SECTION("Default construction")
    {
        dss::ForwardLinkedList<int> list;
        CHECK(list.size() == 0);
        CHECK(list.empty());
        CHECK_THROWS_AS(list.pop_front(), std::out_of_range);
    }

    SECTION("Unit construction")
    {
        dss::ForwardLinkedList<int> list{5};
        CHECK(list.size() == 1);
        CHECK_FALSE(list.empty());
    }
}
