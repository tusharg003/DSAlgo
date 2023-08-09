#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL)
	{
		cout << "L" << root->left->data;
	}

	if (root->right != NULL)
	{
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int> *takeInput()
{
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	if (rootData == -1)
	{
		return NULL;
	}

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int> *leftChild = takeInput();
	BinaryTreeNode<int> *rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;

	/*
		Enter data
		1
		Enter data
		2
		Enter data
		-1
		Enter data
		-1
		Enter data
		3
		Enter data
		-1
		Enter data
		-1

		1:L2R3
		2:
		3:
	*/
}
BinaryTreeNode<int> *takeInputLevelWise()
{
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1)
	{
		return NULL;
	}

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1)
		{
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1)
		{
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
	/*
	Enter data
1
Enter data
2
Enter data
3
Enter data
-1
Enter data
-1
Enter data
-1
Enter data
-1
1:L2
2:L3
3:
PS C:\Users\Tushar Gupta\Desktop\DSA> .\Binary_Tree\BinaryTreeUse.exe
Enter root data
1
Enter left child of 1
2
Enter right child of 1
3
Enter left child of 2
4
Enter right child of 2
5
Enter left child of 3
-1
Enter right child of 3
-1
Enter left child of 4
-1
Enter right child of 4
-1
Enter left child of 5
-1
Enter right child of 5
-1

1:L2R3
2:L4R5
4:
5:
3:
	*/
}
int main()
{
	/*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	root->left = node1;
	root->right = node2;
	*/
	BinaryTreeNode<int> *root = takeInputLevelWise();
	printTree(root);
	delete root;
}
