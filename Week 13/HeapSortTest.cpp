#include <iostream>
#include <vector>
#include "Heap.h"

using namespace std;

void HeapSortAscending(vector<int>& array)
{
	Heap<int> heap;
	int i;

	// Push the entire array into the heap
	for (i = 0; i < array.size(); i++)
	{
		heap.push(array[i]);
	}

	// We are assuming (if all goes right) that th elargest item is at the top of the heap
	// Push the largest item to the back of the array
	for (i = array.size() - 1; i >= 0; i--)
	{
		array[i] = heap.peek();
		heap.pop();
	}
}

void HeapSortDescending(vector<int>& array)
{
	Heap<int> heap;
	int i;

	// Push the entire array to the heap
	for (i = 0; i < array.size(); i++)
	{
		heap.push(array[i]);
	}

	// We are assuming (if all goes right) that th elargest item is at the top of the heap
	// Push the largest item to the front of the array
	for (i = 0; i < array.size(); i++)
	{
		array[i] = heap.peek();
		heap.pop();
	}
}

void DisplayVector(vector<int>& array)
{
	for (int i = 0; i < (int)array.size(); i++)
	{
		cout << " " << array[i];
	}

	cout << ".";
}

//int main()
//{
//	cout << "Heap Sort Example" << endl << endl;
//
//	vector<int> array;
//	array.push_back(33);
//	array.push_back(43);
//	array.push_back(23);
//	array.push_back(20);
//	array.push_back(10);
//	array.push_back(22);
//	array.push_back(90);
//	array.push_back(95);
//	array.push_back(86);
//	array.push_back(1);
//
//	// Display the vector
//	DisplayVector(array);
//	cout << endl;
//
//	// Sort ascending
//	HeapSortAscending(array);
//
//	// Display the vector
//	DisplayVector(array);
//	cout << endl;
//
//	// Sort descending
//	HeapSortDescending(array);
//
//	// Display the vector
//	DisplayVector(array);
//	cout << endl;
//
//	return 0;
//}