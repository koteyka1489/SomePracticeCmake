#include <iostream>
#include <concepts>
#include <vector>
#include <string>


template<typename T>
struct Node
{
	explicit Node(T data) : Data(data) {}
	Node<T>* Next = nullptr;
	T Data;
};



template<typename T>
class LinkedList
{
public:


	LinkedList() = default;

	template<typename U>
	requires std::same_as<T, U>
	LinkedList(U data) {
		Head = new Node<U>(data);
		++Num;
	}

	template<typename U>
	requires std::same_as<T, U>
	LinkedList(std::initializer_list<U> args) {
		for (const auto& arg : args) {
			this->PushBack(arg);
		}
	}

	~LinkedList() {
		while (Head) {
			auto Temp = Head;
			Head = Temp->Next;
			delete Temp;
		}
	}

	template<typename U>
	requires std::same_as<T, U>
	void PushBack(U data) {
		Node<U>* NewNode = new Node<U>(data);
		if (Head == nullptr) {
			Head = new Node<U>(data);
		}
		else if (Head->Next == nullptr)	{
			Head->Next = NewNode;
			Tail = NewNode;
		}
		else {
			Tail->Next = NewNode;
			Tail = NewNode;
		}
		++Num;
	}

	void PopBack() {
		if (Head == nullptr || Num == 0) return;

		if (Tail == nullptr || Num == 1) {
			delete Head;
			Head = nullptr;
		}
		else
		{
			if (Num > 2) {
				auto Current = Head;
				while (Current->Next != Tail)
				{
					Current = Current->Next;
				}
				Current->Next = nullptr;
				delete Tail;
				Tail = Current;
			}
			else
			{
				Head->Next = nullptr;
				delete Tail;
				Tail = nullptr;
			}
		}
		--Num;
	}

	int GetNum() {
		return Num;
	}

	bool IsEmpty() {
		return Num == 0;
	}

	void Empty() {
		while (Head) {
			auto Temp = Head;
			Head = Temp->Next;
			delete Temp;
		}
		Num = 0;
	}
private:
	Node<T>* Head = nullptr;
	Node<T>* Tail = nullptr;
	int Num = 0;


public:

	// ITERATORS
	class Iterator
	{
	public:
		Node<T>* Current;

		Iterator(Node<T>* node) : Current(node)	{ }

		T& operator*() {
			return Current->Data;
		}

		Iterator operator++ () {
			Current = Current->Next;
			return *this;
		}

		Iterator operator++ (int) {
			Iterator Temp = *this;
			Current = Current->Next;
			return Temp;
		}

		bool operator!=(const Iterator& rhs) const {
			return Current != rhs.Current;
		}

		bool operator==(const Iterator& rhs) const {
			return Current == rhs.Current;
		}
	};
	
	Iterator begin() {
		return Iterator(Head);
	}
	Iterator end() {
		return Iterator(nullptr);
	}

};


