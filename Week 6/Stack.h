#pragma once
// Array implementation of a Stack
#include <cassert>

template <class T>
class Stack
{
public:
	// Constructor
	Stack(int size, int growBy = 1) :
		m_array(nullptr), m_size(0), m_top(-1), m_growSize(0)
	{
		if (size)
		{
			m_size = size;
			m_array = new T[m_size];	// Dynamically allocating an array to m_size

			memset(m_array, 0, sizeof(T) * m_size);	// Explicitly allocating memory based on the type T

			m_growSize = ((growBy > 0) ? growBy : 0);	// Set growSize to a positive value or default to 0
		}
	}
	
	// Destructor
	~Stack()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	// ------------- STACK FUNCTIONS ------------------
	void push(T val)
	{
		assert(m_array != nullptr);

		// Check to see if the stack is full. If it is then expand it
		if (isFull())
		{
			Expand();
		}

		m_array[++m_top] = val;	// Increment m_top THEN insert val into the stack.

		// ++m_top;
		// m_array[m_top] = val
	}

	void pop()
	{
		if (!isEmpty())
		{
			m_top--;	// Decrements the top by one. Essentially "ignores" the previous top element
		}
	}

	const T& top()
	{
		assert(m_array != nullptr);
		assert(m_top >= 0);				// Check to see if m_top represents to an actual element in the stack

		return m_array[m_top];
	}

	// Gets and Sets
	int GetSize()
	{
		return m_top + 1;
	}
	int GetMaxSize()
	{
		return m_size;
	}
	bool isEmpty()
	{
		return (m_top == -1); // Check if the stack is empty
	}
	bool isFull()
	{
		return (m_top == m_size - 1); // Compare the number of items in the stack to the value of m_top (or the top of the stack)
	}
private:
	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		// Create the new array
		T* temp = new T[m_size + m_growSize];
		assert(temp != nullptr);

		// Copy the elements of the original array to the new array
		memcpy(temp, m_array, sizeof(T) * m_size);

		// Delete the old array
		delete[] m_array;

		// Clean up variables
		m_array = temp;
		temp = nullptr;

		m_size += m_growSize;

		return true;
	}

	// Variables
	T* m_array;		// Pointer to the beginning of the array

	int m_top;		// Represent the top of our stack
	int m_size;		// Size of our stack
	int m_growSize;	// How much will the stack grow by?
};