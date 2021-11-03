#include <iostream>
#include "Deque.h"

using namespace std;

//int main()
//{
//	cout << "Deque Data Structure Example " << endl << endl;
//
//	// Create and populate our queue
//	const int SIZE = 10;
//	Deque<int> intDeque(SIZE);
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		intDeque.push_back(10 + i);
//	}
//
//	cout << "Deque Contents (Size - " << intDeque.GetSize() << ") :" << endl;
//	while (intDeque.isEmpty() == false)
//	{
//		cout << " Front: " << intDeque.front();
//		cout << " Back: " << intDeque.back();
//		cout << endl;
//		intDeque.pop_back();
//	}
//
//	cout << endl << endl;
//
//	if (intDeque.isEmpty() == true)
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