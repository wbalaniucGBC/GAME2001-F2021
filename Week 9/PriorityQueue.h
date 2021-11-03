#pragma once

#include "PriorityQueueLinkedList.h"

template<class T, class CMP>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}

	// Priority Queue Functions
	void push(T val)
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0)
		{
			m_elements.Push_Back(val);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Begin();

			CMP cmp;	// Placeholder for the comparisons

			while (it.isValid())
			{
				if (cmp(val, *it))
				{
					break;	// Move the iterator to the place where we want to insert the new node into
				}

				it++;
			}

			if (it.isValid())
			{
				m_elements.Insert_Before(it, val);
			}
			else
			{
				m_elements.Push_Back(val);
			}
		}
	}

	void pop()
	{
		m_elements.Pop_Front();
	}

	T& front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();

		return *it;
	}
	T& back()
	{
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it;
	}

	// Helper functions
	int GetSize()
	{
		return m_elements.GetSize();
	}

	int GetMaxSize()
	{
		return m_size;
	}

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}

	void Resize(int size)
	{
		assert(size > 0);
		m_size = size;
	}

private:
	LinkedList<T> m_elements; // Priority Queue Linked List
	int m_size;
};