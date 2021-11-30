#include <iostream>
#include "KDTree.h"

using namespace std;

int main(int args, char** argc)
{
    cout << "KD Trees" << endl;
    cout << endl;

    // Create KD tree and populate it.
    KdTree<int> kdTree(3);

    for (int i = 0; i < 100; i++)
    {
        vector<int> key(3);

        key[0] = rand() % 100;
        key[1] = rand() % 100;
        key[2] = rand() % 100;

        kdTree.push(key);
    }

    // Display range of values that falls within the range.
    vector<int> low(3), high(3);

    low[0] = 20;
    low[1] = 20;
    low[2] = 20;

    high[0] = 70;
    high[1] = 70;
    high[2] = 70;

    cout << "Range (20, 30, 25) (90, 70, 80) Match:" << endl;
    kdTree.displayRange(low, high);
    cout << endl << endl;

    return 1;
}