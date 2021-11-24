#include <iostream>
using namespace std;

class Node
{
public:
	// Constructor
	Node(int obj) : m_object(obj), m_next(nullptr), m_prev(nullptr), m_child(nullptr)
	{
		cout << "Node " << obj << " created!" << endl;
	}

	// Destructor
	~Node()
	{
		m_prev = nullptr;	// Points to a parents

		if(m_child != nullptr)
		{
			// I HAVE A CHILD!
			delete m_child;
		}

		if (m_next != nullptr)
		{
			// I HAVE A SIBLING!
			delete m_next;
		}

		m_child = nullptr;
		m_next = nullptr;

		cout << "Node: " << m_object << " destroyed" << endl;
	}

	// Add a child
	void AddChild(Node* node)
	{
		// Check if the node has a child or not
		if (m_child == nullptr)
		{
			// No child
			m_child = node;
		}
		else
		{
			// The node has a child!. Ad a sibling instead.
			m_child->AddSibling(node);
		}
	}

	// Add a sibling 
	void AddSibling(Node* node)
	{
		Node* ptr = m_next;	// m_next refers to our siblings, if they exist

		if (m_next == nullptr)
		{
			// No siblings. Add the node
			m_next = node;
			node->m_prev = this;
		}
		else
		{
			// Traverse across (potentially) multiple siblings
			while (ptr->m_next != nullptr)
			{
				ptr = ptr->m_next;
			}

			ptr->m_next = node;
			node->m_prev = ptr;
		}
	}

	// Display the Tree - Recursively display each node of the tree
	void DisplayTree()
	{
		cout << m_object;

		// Does this node have siblings?
		if (m_next != nullptr)
		{
			// Sibling exists
			cout << " ";
			m_next->DisplayTree();
		}

		// Does this node have children?
		if (m_child != nullptr)
		{
			cout << endl;
			m_child->DisplayTree();
		}
	}

	// Search the tree (SLOW!) - Linear Search
	bool Search(int value)
	{
		// "Pseudo" Base case
		if (m_object == value)
		{
			// I found my node.
			return true;
		}

		// I have not found my node. Check children, check siblings
		// Check children
		if (m_child != nullptr)
		{
			if (m_child->Search(value) == true)
			{
				return true;
			}
		}

		// Check siblings
		if (m_next != nullptr)
		{
			// I have a sibling
			if (m_next->Search(value) == true)
			{
				return true;
			}
		}

		// Did not find the value being searched
		return false;
	}

private:
	int m_object;
	Node* m_next, * m_prev, * m_child;
};

//int main()
//{
//	cout << "Simple Tree Data Structure Example" << endl << endl;
//
//	// Manually create the tree
//	Node* root = new Node(1);
//	Node* subTree1 = new Node(3);
//
//	root->AddChild(new Node(2));
//
//	subTree1->AddChild(new Node(5));
//	subTree1->AddChild(new Node(6));
//
//	root->AddChild(subTree1);
//
//	root->AddChild(new Node(4));
//
//	// Display the tree
//	cout << "Tree contents by level: " << endl;
//	root->DisplayTree();
//	cout << endl << endl;
//
//	// Test searching
//	cout << "Searching for node 5: ";
//
//	if (root->Search(5) == true)
//	{
//		cout << "Node found!" << endl;
//	}
//	else
//	{
//		cout << "Node not found!" << endl;
//	}
//
//	cout << "Searching for node 9: ";
//	if (root->Search(9) == true)
//	{
//		cout << "Node found!" << endl;
//	}
//	else
//	{
//		cout << "Node not found!" << endl;
//	}
//
//	// Delete the tree
//	delete root;
//
//	cout << endl << endl;
//
//	return 0;
//}