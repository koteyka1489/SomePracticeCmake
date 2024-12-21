#include <LinkedList.h>
#include <gtest/gtest.h>

TEST(LinkedListTests, CreateList)
{
    LinkedList<int> List (1);
    EXPECT_TRUE(List.GetNum() == 1);
    
    LinkedList<int> List1 {1, 2, 3, 4, 5, 6};
    EXPECT_TRUE(List1.GetNum() == 6);

    LinkedList<int> List2{};
    EXPECT_TRUE(List2.GetNum() == 0);

    LinkedList<int> List3;
    EXPECT_TRUE(List3.GetNum() == 0);
}

TEST(LinkedListTests, PushPopList)
{
    LinkedList<int> List;

    List.PopBack();
    EXPECT_TRUE(List.GetNum() == 0);

    List.PushBack(2);
    List.PushBack(3);
    List.PushBack(4);
    List.PushBack(5);
    EXPECT_TRUE(List.GetNum() == 4);

    List.PopBack();
    List.PopBack();
    List.PopBack();
    EXPECT_TRUE(List.GetNum() == 1);

    List.PopBack();
    List.PopBack();
    List.PopBack();
    EXPECT_TRUE(List.GetNum() == 0);

    List.PushBack(2);
    EXPECT_TRUE(List.GetNum() == 1);

    LinkedList<float> List2{1.0555f, 2.2f, 3.3f, 4.4f, 5.5f};
    List2.Empty();
    EXPECT_TRUE(List2.GetNum() == 0);
    EXPECT_TRUE(List2.IsEmpty());


}
