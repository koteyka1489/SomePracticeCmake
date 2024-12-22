#include <LinkedList.h>
#include <array>
#include <gtest/gtest.h>

TEST(LinkedListTests, CreateList)
{
    LinkedList<int> List(1);
    EXPECT_TRUE(List.GetNum() == 1);

    LinkedList<int> List1{1, 2, 3, 4, 5, 6};
    EXPECT_TRUE(List1.GetNum() == 6);

    LinkedList<int> List2{};
    EXPECT_TRUE(List2.GetNum() == 0);

    LinkedList<int> List3;
    EXPECT_TRUE(List3.GetNum() == 0);
}

TEST(LinkedListTests, PushPop)
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

TEST(LinkedListTests, GetFrontTail)
{
    LinkedList<char> List{'a', 'b', 'c'};

    EXPECT_TRUE(List.GetFrontData() == 'a');

    LinkedList<int> List1(1);
    EXPECT_TRUE(List1.GetFrontData() == 1);

    List1.PushBack(2);
    List1.PushBack(3);
    EXPECT_TRUE(List1.GetFrontData() == 1);

    List1.PopBack();
    EXPECT_TRUE(List1.GetFrontData() == 1);

    LinkedList<char> List2{};
    EXPECT_TRUE(List2.GetFrontData() == NULL);
    List2.PushBack('x');
    List2.PushBack('y');
    EXPECT_TRUE(List2.GetFrontData() == 'x');
    EXPECT_TRUE(List2.GetTailData() == 'y');
    List2.PopBack();
    EXPECT_TRUE(List2.GetTailData() == NULL);
}

TEST(LinkedListTests, Sort)
{
    LinkedList<int> List{2, 1};
    List.Sort();
    EXPECT_TRUE(List.GetFrontData() == 1);
    EXPECT_TRUE(List.GetFrontNode()->Next->Data == 2);

    LinkedList<char> ListChar{'c', 'a'};
    ListChar.Sort();
    EXPECT_TRUE(ListChar.GetFrontData() == 'a');
    EXPECT_TRUE(ListChar.GetFrontNode()->Next->Data == 'c');


}
