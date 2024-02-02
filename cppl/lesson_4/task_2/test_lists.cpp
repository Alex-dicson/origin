#include <iostream>
#include "lists.cpp"
#include "catch2/catch_test_macros.hpp"
#include "Catch2/catch_session.hpp"

TEST_CASE("Lists", "[task_2]")
{
    List test;

    SECTION("Test function PushBack")
    {
        test.PushBack(3);
        test.PushBack(4);
        INFO("incorrect size after being added to the end of the list");
        CHECK(test.Size() == 2);
        auto val = test.PopBack();
        INFO("incorrect deletion");
        CHECK(val == 4);
    }

    SECTION("Test function PushFront")
    {
        test.Clear();
        test.PushFront(-7);
        test.PushFront(0);
        test.PushFront(5);
        test.PushFront(59);
        INFO("incorrect size after being added to the top of the list");
        CHECK(test.Size() == 4);
        auto val = test.PopFront();
        INFO("incorrect deletion");
        CHECK(val == 59);
    }

    SECTION("Test function PopBack")
    {
        test.Clear();
        INFO("deleting an item in an empty list");
        CHECK(test.PopBack());
        test.PushBack(8);
        test.PushBack(13);
        test.PushBack(28);
        auto val = test.PopBack();
        INFO("incorrect deletion");
        CHECK(val == 28);
    }

    SECTION("Test function PopFront")
    {
        test.Clear();
        INFO("deleting an item in an empty list");
        CHECK(test.PopBack());
        test.PushBack(8);
        test.PushBack(13);
        test.PushBack(19);
        auto val = test.PopFront();
        INFO("incorrect deletion");
        CHECK(val == 8);
    }

}


int main()
{
    return Catch::Session().run();
    return 0;
}
