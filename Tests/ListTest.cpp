#include <LinkedList.h>
#include <gtest/gtest.h>

TEST(LinkedListTests, CreateList)
{
    LinkedList<int> List (1);
    ASSERT_TRUE(List.GetNum() == 1);

    LinkedList<int> List1 {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(List1.GetNum() == 6);

    LinkedList<int> List2{};
    ASSERT_TRUE(List2.GetNum() == 0);

    LinkedList<int> List3;
    ASSERT_TRUE(List3.GetNum() == 0);
}

TEST(LinkedListTests, PushPopList)
{
    LinkedList<int> List;

    List.PopBack();
    ASSERT_TRUE(List.GetNum() == 0);

    List.PushBack(2);
    List.PushBack(3);
    List.PushBack(4);
    List.PushBack(5);
    ASSERT_TRUE(List.GetNum() == 4);

    List.PopBack();
    List.PopBack();
    List.PopBack();
    ASSERT_TRUE(List.GetNum() == 1);

    List.PopBack();
    List.PopBack();
    List.PopBack();
    ASSERT_TRUE(List.GetNum() == 0);

    List.PushBack(2);
    ASSERT_TRUE(List.GetNum() == 1);
}
