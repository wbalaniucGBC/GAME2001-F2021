#pragma once
#include <cassert>

template<class T>
class OrderedArray
{
public:
	// Constructor
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)	// Is this a legal size for an array?
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];		// Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize);	// Explicitly set 0 to all elements in the array

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	~OrderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	// Insertion -- Big-O = O(N)
	void push(T val)
	{
		assert(m_array != nullptr);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k;	// i - Index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index(i) forward by one. Work backwards
		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		// Step 3: Insert val into the array at index
		m_array[i] = val;

		m_numElements++;

		// return i;
	}
	// Deletion (2 ways)
	// Remove the last item inserted into the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;	// Reduce the total number of elements by 1. Ignoring the last element.
		}
	}
	// Remove an item given an index
	// (Almost) Brute-force execution -- Big-O = O(N)
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{
			// I am trying to remove something outside of the bounds of the array
			return;	// <-- Maybe could do some form of exception handling
		}

		for (int i = index; i < m_numElements; i++)
		{
			// Start at the index we want to remove.
			// Shift everything after index back by one.
			if (i + 1 < m_numElements)	// Confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	// Searching
	// Binary Search
	int search(T searchKey)
	{
		// Call to binary search recursive function
		// Binary Search: searchKey, initial lowerBound, initial upperBound
		return binarySearch(searchKey, 0, m_numElements - 1);
	}
	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	// Clear
	void clear()
	{
		m_numElements = 0;	 // Ignore (or forgets) all current items in the array
	}
	// Gets and Sets
	int GetSize()
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
private:
	// Private functions
	// Recursive Binary Search
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < m_numElements);

		// Bitwise divide by 2
		int current = (lowerBound + upperBound) >> 1;

		// Check 1 "Base case": Did we find the searchKey at the current index?
		if (m_array[current] == searchKey)
		{
			// We found it! Return the index
			return current;
		}
		// Check 2 "Base base": Are we done searching? 
		else if (lowerBound > upperBound)
		{
			// Did not find searchKey within m_array
			return -1;
		}
		// Check 3: Which half of the array is searchKey in?
		else
		{
			if (m_array[current] < searchKey)
			{
				// Search the upper half of the array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				// Search the lower half of the array
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}

		return -1;
	}
	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			// LEAVE!
			return false;
		}

		// Create the new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		// Copy the contents of the original array into the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		// Delete the old array
		delete[] m_array;

		// Clean up variable assignments
		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;

		return true;
	}
private:
	// Private Variables
	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;		// Maximum size of the array
	int m_growSize;		// Amount the array can grow through expansion
	int m_numElements;	// Number of items currently in my array
};