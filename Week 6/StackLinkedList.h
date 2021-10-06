#pragma once
#include <cassert>
#include "DoublyLinkedList.h"

template <class T>
class Stack
{
public:
	// Constructor and Destructor
	Stack() {}
	~Stack() {}
	// -------------- Stack Functions ------------
	void push(T val)
	{
		m_container.Push_Back(val);
	}
	void pop()
	{
		m_container.Pop_Back();
	}
	const T& top()
	{
		LinkIterator<T> it;
		it = m_container.Last();
		return *it;
	}

	// Gets and Sets
	int GetSize()
	{
		return m_container.GetSize();
	}
	bool isEmpty()
	{
		return (m_container.GetSize() == 0);
	}

private:
	LinkedList<T> m_container;
};