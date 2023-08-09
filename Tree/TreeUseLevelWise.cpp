#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);

	queue<TreeNode<int> *> pendingNodes;

	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++)
		{
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int> *child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int> *takeInput()
{
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		TreeNode<int> *child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int> *root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++)
	{
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); i++)
	{
		printTree(root->children[i]);
	}
}
void printLevelWise(TreeNode<int> *root)
{
	// Write your code here
	if (root == NULL)
		return;
	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0)
	{
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << front->data << ":";
		for (int i = 0; i < front->children.size(); i++)
		{
			if (i + 1 != front->children.size())
				cout << front->children[i]->data << ",";
			else
				cout << front->children[i]->data;

			pendingNodes.push(front->children[i]);
		}
		cout << endl;
	}
}

int numNodes(TreeNode<int> *root)
{
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++)
	{
		ans += numNodes(root->children[i]);
	}
	return ans;
}

// --------------------------------sum of nodes!-------------------------------------------------------------

int sumOfNodes(TreeNode<int> *root)
{
	// Write your code here
	if (root == NULL)
		return 0;
	int sum = root->data;
	for (int i = 0; i < root->children.size(); i++)
	{
		sum += sumOfNodes(root->children[i]);
	}
	return sum;
}
// ------------------------------Max data Node-------------------------------------------------

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
	// Write your code here
	if (root == NULL)
		return NULL;
	int mx = root->data;
	TreeNode<int> *ans = root;
	for (int i = 0; i < root->children.size(); i++)
	{
		TreeNode<int> *temp = maxDataNode(root->children[i]);
		if (temp->data > mx)
		{
			mx = temp->data;
			ans = temp;
		}
	}
	return ans;
}
//------------------------------Find height of tree----------------------------------------------

int getHeight(TreeNode<int> *root)
{

	if (root == NULL) // edge case just to stay safe
		return 0;
	int ans = 0;
	for (int i = 0; i < root->children.size(); i++)
	{
		int height = getHeight(root->children[i]);
		if (height > ans)
			ans = height;
	}
	return ans + 1;
}
//------------------------------Print at Depth k------------------------------------------

void printAtLevelK(TreeNode<int> *root, int k)
{
	if (root == NULL) // edge case just to stay safe
		return;
	if (k == 0)
	{
		cout << root->data << endl;
		return;
	}
	for (int i = 0; i < root->children.size(); i++)
	{
		printAtLevelK(root->children[i], k - 1);
	}
}
//------------------------------Count number of leaf Nodes-------------------------------------
int getLeafNodeCount(TreeNode<int> *root)
{
	// Write your code here
	if (root == NULL) // edge case just to stay safe
		return 0;
	if (root->children.size() == 0)
		return 1;
	int ans = 0;
	for (int i = 0; i < root->children.size(); i++)
	{
		ans += getLeafNodeCount(root->children[i]);
	}
	return ans;
}
// --------------------------------Post order traversal -- children->root----------------------------

void printPostOrder(TreeNode<int> *root)
{
	// Write your code here
	if (root == NULL)
	{
		return;
	}
	for (int i = 0; i < root->children.size(); i++)
		printPostOrder(root->children[i]);
	cout << root->data << " ";
}
//  --------------------------------Pre Order Traversal - Root then childern---------------------------
void preorder(TreeNode<int> *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	for (int i = 0; i < root->children.size(); i++)
	{
		preorder(root->children[i]);
	}
}
int main()
{
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int> *root = takeInputLevelWise();
	printLevelWise(root);

	cout << numNodes(root) << endl;
	// TODO delete the tree

	delete root;
}
