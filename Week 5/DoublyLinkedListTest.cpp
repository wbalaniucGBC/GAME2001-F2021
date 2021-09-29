#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main()
{
	cout << "Doubly Linked List Example" << endl << endl;

	LinkedList<int> lList;

	// 701 1 301  

	lList.Push_Back(101);
	lList.Push_Front(201);
	lList.Pop_Back();
	lList.Push_Back(301);
	lList.Pop_Front();
	lList.Push_Back(401);
	lList.Push_Front(1);
	lList.Pop_Back();
	lList.Push_Front(701);

	LinkIterator<int> it;

	for (it = lList.Begin(); it != lList.End(); it++)
	{
		cout << " " << *it;
	}

	cout << endl << endl;

	for (it = lList.Last(); it != nullptr; it--)
	{
		cout << " " << *it;
	}

	cout << endl << endl;

	return 0;
}