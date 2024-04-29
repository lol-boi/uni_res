#include <iostream>
using namespace std;

class BTreeNode {
	int* keys;
	int t; 
	BTreeNode** C;
	int n; 
	bool leaf; 
public:
	BTreeNode(int _t, bool _leaf);
	void traverse();
	BTreeNode*
	search(int k); 
	friend class BTree;
};

class BTree {
	BTreeNode* root;
	int t;
public:
	BTree(int _t)
	{
		root = NULL;
		t = _t;
	}

	// function to traverse the tree
	void traverse()
	{
		if (root != NULL)
			root->traverse();
	}

	// function to search a key in this tree
	BTreeNode* search(int k)
	{
		return (root == NULL) ? NULL : root->search(k);
	}
};

// Constructor for BTreeNode class
BTreeNode::BTreeNode(int _t, bool _leaf)
{
	// Copy the given minimum degree and leaf property
	t = _t;
	leaf = _leaf;

	// Allocate memory for maximum number of possible keys
	// and child pointers
	keys = new int[2 * t - 1];
	C = new BTreeNode*[2 * t];

	// Initialize the number of keys as 0
	n = 0;
}

// Function to traverse all nodes in a subtree rooted with
// this node
void BTreeNode::traverse()
{
	// There are n keys and n+1 children, traverse through n
	// keys and first n children
	int i;
	for (i = 0; i < n; i++) {
		// If this is not leaf, then before printing key[i],
		// traverse the subtree rooted with child C[i].
		if (leaf == false)
			C[i]->traverse();
		cout << " " << keys[i];
	}

	// Print the subtree rooted with last child
	if (leaf == false)
		C[i]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k)
{
	// Find the first key greater than or equal to k
	int i = 0;
	while (i < n && k > keys[i])
		i++;

	// If the found key is equal to k, return this node
	if (keys[i] == k)
		return this;

	// If the key is not found here and this is a leaf node
	if (leaf == true)
		return NULL;

	// Go to the appropriate child
	return C[i]->search(k);
}
