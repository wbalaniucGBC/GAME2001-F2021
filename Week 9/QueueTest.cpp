#include <iostream>
#include "Queue.h"

using namespace std;

//int main()
//{
//	cout << "Queue Data Structure Example " << endl << endl;
//
//	// Create and populate our queue.
//	const int SIZE = 5;
//	Deque<int> intQueue(SIZE);
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		intQueue.push(10 + i);
//	}
//
//	cout << "Queue Contents (Size - " << intQueue.GetSize() << ") :" << endl;
//
//	while (intQueue.isEmpty() == false)
//	{
//		cout << " Front: " << intQueue.front();
//		cout << " Back: " << intQueue.back();
//		cout << endl;
//		intQueue.pop();
//	}
//
//	cout << endl << endl;
//
//	if (intQueue.isEmpty() == true)
//	{
//		cout << "The int queue is empty." << endl << endl;
//	}
//	else
//	{
//		cout << "The int queue is NOT empty." << endl << endl;
//	}
//
//	return 0;
//}