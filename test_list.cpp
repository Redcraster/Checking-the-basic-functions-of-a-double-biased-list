#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>   
#include "my_list.h"         

int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}

TEST_CASE("List.Empty()") {
    List myList;

    SECTION("Пустой список сразу после создания") {
        REQUIRE(myList.Empty() == true);
    }

    SECTION("Список после добавления элементов") {
        myList.PushBack(10);
        myList.PushFront(20);
        REQUIRE(myList.Empty() == false);
    }

    SECTION("Список после очистки") {
        myList.PushBack(1);
        myList.PushFront(2);
        myList.Clear();
        REQUIRE(myList.Empty() == true);
    }
}

TEST_CASE("List.Size()") {
    List myList;

    SECTION("Сразу после создания размер = 0") {
        REQUIRE(myList.Size() == 0);
    }

    SECTION("После добавления нескольких элементов") {
        myList.PushBack(1);
        myList.PushBack(2);
        myList.PushFront(3);
        REQUIRE(myList.Size() == 3);
    }

    SECTION("После очистки размер = 0") {
        myList.PushBack(1);
        myList.PushBack(2);
        myList.PushFront(3);
        REQUIRE(myList.Size() == 3);

        myList.Clear();
        REQUIRE(myList.Size() == 0);
    }
}

TEST_CASE("List.Clear()") {
    List myList;

    SECTION("Очистка пустого списка не вызывает ошибок и не меняет размер") {
        REQUIRE_NOTHROW(myList.Clear());
        REQUIRE(myList.Size() == 0);
        REQUIRE(myList.Empty() == true);
    }

    SECTION("Очистка непустого списка приводит к пустому списку") {
        myList.PushBack(5);
        myList.PushBack(10);
        myList.PushBack(15);
        REQUIRE(myList.Size() == 3);
        REQUIRE(myList.Empty() == false);

        myList.Clear();
        REQUIRE(myList.Size() == 0);
        REQUIRE(myList.Empty() == true);

        REQUIRE_NOTHROW(myList.Clear());
    }
}
