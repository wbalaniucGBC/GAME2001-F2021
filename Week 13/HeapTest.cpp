#include <iostream>
#include "Heap.h"
using namespace std;

//int main()
//{
//	cout << "Heap Example!" << endl << endl;
//
//	Heap<int> heap(10);
//	
//	heap.push(100);
//	heap.push(50);
//	heap.push(70);
//	heap.push(20);
//	heap.push(10);
//	heap.push(99);
//	heap.push(35);
//	heap.push(40);
//
//	// When I pop, it should be in the following order:
//	// 100, 99, 70, 50, 40, 35, 20, 10
//
//	cout << "Size: " << heap.size() << endl << endl;
//
//	while (heap.size() > 0)
//	{
//		cout << heap.peek() << endl;
//		heap.pop();
//	}
//
//	return 0;
//}