#include <iostream>
// #include "Stack.h"
// #include "StackArray.h"
#include "StackLinkedList.h"
using namespace std;

int main()
{
	cout << "Stack using LinkedList Example" << endl << endl;

	Stack<int> sStack;

	sStack.push(101);
	sStack.push(501);
	sStack.push(201);
	sStack.pop();
	sStack.push(301);
	sStack.push(401);
	sStack.push(901);
	sStack.pop();
	sStack.pop();

	// 301 501 101

	cout << "Contents of the stack: ";
	// while(sStack.isEmpty() == false)
	while (!sStack.isEmpty())
	{
		cout << " " << sStack.top();
		sStack.pop();
	}

	cout << endl << endl;

	return 0;
}