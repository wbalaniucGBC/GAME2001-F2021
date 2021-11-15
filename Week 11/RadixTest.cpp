#include <iostream>
#include <deque>

using namespace std;

#define BASE			10
#define MAX_POSITIONS	2

void RadixSort(int* array, int size)
{
	// Base index, radix index and a counter
	int b = 0, r = 0, i = 0;
	// Container counters, base factor
	int index = 0, factor = 0;

	deque<int> qList[BASE];

	for (b = 1, factor = 1; b <= MAX_POSITIONS; factor *= BASE, b++)
	{
		// Read each value from the array and determine where in the deque it belongs based on it's base value
		for (r = 0; r < size; r++)
		{
			index = (array[r] / factor) % BASE;	// "Isolates" the column value and saves it to index
			qList[index].push_back(array[r]);
		}

		// Remove in order from the deque into the original array
		for (r = 0, i = 0; r < BASE; r++)
		{
			while (qList[r].empty() != true)
			{
				array[i++] = qList[r].front();
				qList[r].pop_front();
			}
		}
	}
}

int main()
{
	cout << "Radix Sort Example" << endl << endl;

	const int size = 100;
	int array[size];
	int i = 0;

	// Populate array.
	for (i = 0; i < size; i++)
		array[i] = 10 + rand() % 89;

	// Display array contents.
	cout << "Array contents before sort: ";
	for (i = 0; i < size; i++)
		cout << " " << array[i];

	cout << endl;

	// Radix sorting.
	RadixSort(array, size);

	// Display array contents.
	cout << " Array contents after sort: ";
	for (i = 0; i < size; i++)
		cout << " " << array[i];

	cout << endl << endl;
	return 1;
}