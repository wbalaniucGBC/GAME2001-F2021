#pragma once
#include <vector>
using namespace std;

template<class T>
class Heap
{
public:
	// Constructor
	Heap() {}
	// Specifying a minSize is useful to reduce the initial expansion of the vector.
	Heap(int minSize)
	{
		m_heap.reserve(minSize);
	}
	// Insert elements into the end of the array
	// "Bubble" up the values to the correct position.
	void push(T key)
	{
		// Push to the back of the array (m_heap)
		m_heap.push_back(key);

		// Compare the inserted key with the parenbt node and swap if need be.
		int index = (int)m_heap.size() - 1;		// Set "index" to hold the index of the last element
		T temp = m_heap[index];					// Store a copy of the item just added to the heap
		int parentIndex = (index - 1) / 2;		// Find the parent index of any child. 

		// Execute until we find the best position for the inserted element, or the loop ends.
		// Swapping while we traverse upwards through the heap.
		while (index > 0 && temp >= m_heap[parentIndex])
		{
			// Bubble up through the heap
			m_heap[index] = m_heap[parentIndex];	// Sets the element at index equal to the lement at parentIndex
			index = parentIndex;
			parentIndex = (index - 1) / 2;
		}

		// Set the puhys value into the correct location within the heap
		m_heap[index] = temp;
	}

	// Pop work top down.
	// Remove the top element and replace it with the last element.
	// Propogate the new top element down through the heap
	// This ensures the highest value sits up top.
	void pop()
	{
		int index = 0;

		// Replace the top element with the last element of the array. Pop off the last element.
		m_heap[index] = m_heap[(int)m_heap.size() - 1];
		m_heap.pop_back();

		// Check if we still have a heap to propgate through.
		if ((int)m_heap.size() > 0)
		{
			// Restructure the heap such that the largest item is at the top
			T temp = m_heap[index];
			int currentIndex = 0, leftIndex = 0, rightIndex = 0;

			// Check which side of the node we are traversing down
			// Traversal
			while (index < (int)m_heap.size() / 2)
			{
				// Calculate the left index and right index of any element (if they exist)
				leftIndex = 2 * index + 1;	// Return the left child index of any parent index;
				rightIndex = leftIndex + 1;

				// Which side of the parent node are we going down?
				if (rightIndex < (int)m_heap.size() && m_heap[leftIndex] < m_heap[rightIndex]) // Going right?
				{
					// Traverse right
					currentIndex = rightIndex;
				}
				else
				{
					// Traverse left
					currentIndex = leftIndex;
				}

				// Is there a case where I need to exit out of this loop early?
				// When "temp" is greater than what my currentIndex is pointing too.
				// "Early exit"
				if (temp >= m_heap[currentIndex])
				{
					break;
				}

				// ...otherwise, we have to iterate once again.
				// Set the value to move elements upwards through the tree
				m_heap[index] = m_heap[currentIndex];
				index = currentIndex;
			}

			// Assign the node (stored in temp) to the correct position
			m_heap[index] = temp;
		}
	}

	T peek()
	{
		return m_heap[0];
	}

	int size()
	{
		return m_heap.size();
	}
private:
	vector<T> m_heap;
};