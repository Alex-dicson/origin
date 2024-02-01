#include <iostream>
#include "lists.cpp"
#include "catch2/catch_test_macros.hpp"
#include "Catch2/catch_session.hpp"

TEST_CASE("Lists", "[task_1]")
{
    List test;
    CHECK(test.Empty());
    test.PushBack(3);
    test.PushBack(4);
    CHECK(test.Size() == 2);
    test.Clear();
    CHECK(test.Size() == 0);

}

int main(){
    return Catch::Session().run();
}
