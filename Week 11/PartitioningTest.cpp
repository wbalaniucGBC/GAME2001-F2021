#include <iostream>
#include "UnorderedArray.h"

using namespace std;

//int main()
//{
//    cout << "Partitioning Algorithm" << endl;
//    cout << endl;
//
//    const int size = 100;
//    int i = 0;
//    int pivotValue = 60;
//
//    UnorderedArray<int> array(size);
//
//    // Insert elements and print basic stats.
//    for (i = 0; i < size; i++)
//        array.push(rand() % 100);
//
//    cout << "Array size - " << size << " pivot value - "
//        << pivotValue << "." << endl << endl;
//
//    // Display elements.
//    cout << "Before partitioning:";
//
//    for (i = 0; i < size; i++)
//        cout << " " << array[i];
//
//    cout << endl << endl;
//
//    // Partition then display results.
//    int pivot = array.Partition(pivotValue);
//
//    cout << "After partitioning (pivot index - "
//        << pivot << "):";
//
//    for (i = 0; i < size; i++)
//        cout << " " << array[i];
//
//    cout << endl << endl;
//
//    return 1;
//}