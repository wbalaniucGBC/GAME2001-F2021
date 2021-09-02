// "Generic" classes or function
// Compare 2 things. Return smallest. Return the largest.
#include <iostream>
using namespace std;

// Template function
// Check 2 "things". Return the smallest
template <class T>
T min_func(T lVal, T rVal)
{
	if (lVal > rVal)
	{
		return rVal;
	}

	return lVal;
}

// Template function
// Check 2 "things". Return the largest.
template <class T>
T max_func(T lVal, T rVal)
{
	if (lVal < rVal)
	{
		return rVal;
	}

	return lVal;
}

// Implement a template class
template <class T>
class TemplateClass
{
public:
	// Constructor
	TemplateClass(T val)
	{
		m_val = val;
	}
	// MISSING SOMETHING HERE!!!
	bool operator<(TemplateClass& rVal)	// a < b ==> a.operator<(b);
	{
		return m_val < rVal.GetVal();
	}
	bool operator>(TemplateClass& rVal) // a > b ==> a.operator>(b);
	{
		return m_val > rVal.GetVal();
	}
	T GetVal()
	{
		return m_val;
	}
private:
	T m_val;
};

// Main function
int main()
{
	cout << "Template Example" << endl << endl;
	cout << "Min = " << min_func(56.1, 43.6) << endl;
	cout << "Max = " << max_func('c', 'd') << endl;

	// Create 2 "TemplateClass" objects and compare them.
	cout << "Max (objects) = " << max_func(TemplateClass<int>(7), TemplateClass<int>(4)).GetVal();

	return 0;
}