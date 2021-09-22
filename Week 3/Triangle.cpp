// Recurisvely determined the nth term triangular number
#include <iostream>
#include <cassert>
using namespace std;


// Triangle number with a loop
int TriNumLoop(int term)
{
	assert(term >= 1);

	int value = 0;

	// Looping
	for (; term > 0; term--)
	{
		value += term;
	}

	return value;
}

// Triangle number with recursion
int TriNumRecursion(int term)
{
	assert(term >= 1);

	// Base Case
	if (term == 1)
	{
		return 1;
	}

	// Tail recursion
	return(TriNumRecursion(term - 1) + term);
}

// Main function
//int main()
//{
//	cout << "Triangle number example!" << endl;
//
//	// Using loops
//	cout << "The value of the 18th term using a loop is: ";
//	cout << TriNumLoop(18) << endl;
//
//	// Using recursion
//	cout << "The value of the 18th term using recursion is: ";
//	cout << TriNumRecursion(18) << endl << endl;
//
//	return 0;
//}