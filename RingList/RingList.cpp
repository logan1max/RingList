// RingList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

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
	void delByIndex(int index);
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
		toAdd->next = head;
		Node* temp = head;
		for (int i=0; i < size-1; i++)
		{
			temp = temp->next;
		}
		
		temp->next = toAdd;
		size++;
	}
}

void Ring::showRing()
{
	Node* temp = head;
	for (int i = 0; i < size; i++)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void Ring::popFront()
{
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

void Ring::delByIndex(int index)
{
	Node* prev = head;
	for (int i = 0; i < index - 1; i++)
	{
		prev = prev->next;
	}

	Node* toDelete = prev->next;
	prev->next = toDelete->next;
	delete(toDelete);

	size--;
}

int main()
{
	Ring ring;

	ring.pushBack(1);
	ring.pushBack(2);
	ring.pushBack(3);
	ring.pushBack(4);

	ring.showRing();
	cout << endl;

	ring.delByIndex(2);

	ring.showRing();
	cout << endl;
}