#include <iostream>
#include <concepts>
#include <vector>
#include <string>
#include "LinkedList.h"


int main()
{

	LinkedList<int> List(1);
	List.PushBack(2);
	List.PushBack(3);
	List.PushBack(4);
	List.PushBack(5);
	List.PopBack();
	List.PopBack();



	LinkedList<float> List2{ 1.0555f, 2.2f, 3.3f, 4.4f, 5.5f };

	List2.Empty();

	LinkedList<char> List3{ 'p', 'i', 'z', 'd', 'a'};


	std::cout << "List Num - " << List.GetNum() << "\nmembers :\n";
	for (auto& l : List)
	{
		std::cout << l << "\n";
	}

	std::cout << "List2 Num - " << List2.GetNum() << "\nmembers :\n";
	for (auto& l : List2)
	{
		std::cout << l << "\n";
	}

	std::cout << "List3 Num - " << List3.GetNum() << "\nmembers :\n";
	for (auto& l : List3)
	{
		std::cout << l << "\n";
	}

	getchar();


	return 0;
}
