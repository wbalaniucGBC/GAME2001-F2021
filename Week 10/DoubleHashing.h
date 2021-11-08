#pragma once
#include <string>
using namespace std;

template<class T>
class HashItem
{
public:
	HashItem() : m_key("") { }
	~HashItem() { }

	// Gets and sets
	string GetKey()
	{
		return m_key;
	}
	void SetKey(string k)
	{
		m_key = k;
	}

	T GetObject()
	{
		return m_obj;
	}
	void SetObj(T obj)
	{
		m_obj = obj;
	}

	// Overload operator 
	// Equivalence operator
	bool operator==(HashItem& item)	// Allow us to compare 2 HashItem's with each other
	{
		if (m_key == item.GetKey())
		{
			return true;
		}

		return false;
	}

	// Assignment operator
	void operator=(HashItem item)
	{
		m_key = item.GetKey();
		m_obj = item.GetObject();
	}
private:
	string m_key;
	T m_obj;
};

template<class T>
class HashTable
{
public:
	// Constructor and Destructor
	HashTable(int size) : m_table(nullptr), m_size(0), m_totalItems(0)
	{
		if (size > 0) // Input validation
		{
			m_size = GetNextPrimeNum(size);
			m_table = new HashItem<T>[m_size];
		}
	}
	~HashTable()
	{
		if (m_table != NULL)
		{
			delete[] m_table;
			m_table = NULL;
		}
	}
	// Private functions
private:
	bool isNumPrime(int val)
	{
		for (int i = 2; (i * i) <= val; i++) // Checks if val is divisible by i
		{
			if ((val % i) == 0)
			{
				return false;
			}
		}

		return true;
	}
	int GetNextPrimeNum(int val)
	{
		int i;

		for (i = val + 1; ; i++) // "Infinite" for loop
		{
			if (isNumPrime(i))	// Checks if 'i' is a prime number
			{
				break;
			}
		}

		return i;
	}
	// Public functions
public:
	// Insert
	bool Insert(T& obj)
	{
		// Check if the table is full
		if (m_totalItems == m_size)
		{
			// Table is full!
			return false;
		}

		// Get the hash value
		int hash = HashFunction(obj);
		int step = HashFunction2(obj);

		while (m_table[hash].GetKey() != "")
		{
			// Something is there!
			hash += step;
			hash %= m_size;
		}

		// Found an empty spot
		m_table[hash].SetKey(obj.GetHashString());
		m_table[hash].SetObj(obj);

		m_totalItems++;

		return true;
	}
	// Delete
	void Delete(T& obj)
	{
		int hash = HashFunction(obj);
		int step = HashFunction2(obj);
		int originalHash = hash;

		while (m_table[hash].GetKey() != "")
		{
			// Something is there
			if (m_table[hash].GetKey() == obj.GetHashString())
			{
				// Delete this item
				m_table[hash].SetKey("");
				m_totalItems--;

				return;
			}

			// Something there but not what we are looking to delete
			// Double Hashing forward
			hash += step;
			hash %= m_size;

			if (originalHash == hash)
			{
				return;
			}
		}
	}
	// Find
	bool Find(string hashString, T* obj)
	{
		int hash = HashFunction(hashString);
		int step = HashFunction2(hashString);
		int originalHash = hash;

		while (m_table[hash].GetKey() != "")
		{
			// Something is there!
			if (m_table[hash].GetKey() == hashString)
			{
				// Found the object!
				if (obj != nullptr)
				{
					// Not null!
					*obj = m_table[hash].GetObject();
					return true;
				}
			}

			// Something is there, but not what we are looking for
			// Double hashing
			hash += step;
			hash %= m_size;

			if (originalHash == hash)
			{
				return false;
			}
		}

		return false;
	}
	int HashFunction(T& obj)
	{
		return HashFunction(obj.GetHashString());
	}
	int HashFunction(const string& HashString)
	{
		int hash = 0;

		// Iterate through each character of the HashString and accumulate its value
		for (int i = 0; i < HashString.length(); i++)
		{
			hash += HashString[i];
		}

		return hash % m_size;	// Constrain our hash value to 0 up to m_size
	}
	// ----------------------- DOUBLE HASHING FUNCTIONS -----------------------------
	int HashFunction2(T& obj)
	{
		return HashFunction2(obj.GetHashString());
	}
	int HashFunction2(const string& HashString)
	{
		int hash = 0;

		for (int i = 0; i < HashString.length(); i++)
		{
			hash = (hash * 256 + HashString[i]) % m_size;
		}

		return hash;
	}

	int GetSize()
	{
		return m_size;
	}
	int GetTotalItems()
	{
		return m_totalItems;
	}
private:
	HashItem<T>* m_table;	// Defines a pointer to the beginning of an array
	int m_size, m_totalItems;	// Size of the hash table and total items in the hash table
};