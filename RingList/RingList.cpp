// RingList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Ring
{
private:
	class Node
	{
	public:
		int data;
		Node* next;

		Node() 
		{
			data = NULL;
			next = NULL;
		}
	};
	Node* head;

	int size;
public:
	Ring();
	~Ring();

	int GetSize() { return size; }

	void pushBack(int data);
	void showRing();
	void popFront();
};

Ring::Ring()
{
	head = NULL;
	size = 0;
}

Ring::~Ring()
{
	if (size == 1)
	{
		delete head;
	}
	else
	{
		while (size)
		{
			popFront();
		}
	}
}

void Ring::pushBack(int data)
{
	if (head==NULL)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = newNode;
		head = newNode;
		size++;
	}
	else
	{
		Node* toAdd = new Node();
		toAdd->data = data;
		toAdd->next = NULL;
		Node* temp = head;
		/*for (int i=0; i < size; i++)
		{
			temp = temp->next;
		}*/
		while (temp->next != temp)
		{
			temp = temp->next;
		}
		temp->next = toAdd;
		toAdd->next = head;
		size++;
	}
}

void Ring::showRing()
{
}

void Ring::popFront()
{
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

int main()
{
	Ring ring;

	ring.pushBack(1);
	ring.pushBack(2);
	ring.pushBack(3);
}