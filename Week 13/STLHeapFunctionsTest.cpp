#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cout << "STL Heap Functions" << endl << endl;

	int myInts[] = { 10, 20, 30, 5, 15 };
	vector<int> v(myInts, myInts + 5);

	make_heap(v.begin(), v.end());
	cout << "Initial max heap: " << v.front() << endl;

	pop_heap(v.begin(), v.end());
	v.pop_back();
	cout << "Max heap after pop: " << v.front() << endl;

	v.push_back(99);
	push_heap(v.begin(), v.end());
	cout << "Max after push: " << v.front() << endl;

	sort_heap(v.begin(), v.end());

	cout << "Final sorted range: ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << " " << v[i];
	}

	cout << endl << endl;

	return 0;
}