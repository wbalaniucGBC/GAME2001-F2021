#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	cout << "Binary Tree!" << endl << endl;

	BinaryTree<int> binaryTree;

	binaryTree.push(20);
	binaryTree.push(10);
	binaryTree.push(12);
	binaryTree.push(27);
	binaryTree.push(9);
	binaryTree.push(50);
	binaryTree.push(33);
	binaryTree.push(6);

	binaryTree.remove(27);

	if (binaryTree.search(20) == true)
	{
		cout << "The key 20 found!" << endl;
	}
	else
	{
		cout << "The key 20 not found!" << endl;
	}

	if (binaryTree.search(14) == true)
	{
		cout << "The key 14 found!" << endl;
	}
	else
	{
		cout << "The key 14 not found!" << endl;
	}

	if (binaryTree.search(27) == true)
	{
		cout << "The key 27 found!" << endl;
	}
	else
	{
		cout << "The key 27 not found!" << endl;
	}

	cout << endl << endl;

	cout << "Pre-order: ";
	binaryTree.DisplayPreOrder();
	cout << endl;

	cout << "Post-order: ";
	binaryTree.DisplayPostOrder();
	cout << endl;

	cout << "In-order: ";
	binaryTree.DisplayInOrder();
	cout << endl;

	return 0;
}