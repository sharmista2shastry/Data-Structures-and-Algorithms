/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
  
  Time Complexity => O(n), Space Complexity => O(n)

***********************************************************
#include<vector>
#include<queue>

void changeBST(BinaryTreeNode<int> *root, vector<int> arr, int &index)
{
	if(root == NULL)
	return;

	changeBST(root->right, arr, index);

	root->data = arr[index--];

	changeBST(root->left, arr, index);

	return;
}

void convertToArray(BinaryTreeNode<int> *root, vector<int> &arr)
{
	if(root == NULL)
	return;

	convertToArray(root->left, arr);

	arr.push_back(root->data);

	convertToArray(root->right, arr);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
	vector<int> arr;
	convertToArray(root, arr);

	for(int i=arr.size()-2; i>=0; i--)
	arr[i] += arr[i+1];

	int index = arr.size()-1;

	changeBST(root, arr, index);
}*/

int changeBST(BinaryTreeNode<int> *root, int sum)
{
	if(root == NULL)
	return 0;

	int right = changeBST(root->right, sum);
	int rootdata = root->data;
	root->data = root->data + right + sum;
	int left = changeBST(root->left, root->data);

	return rootdata + right + left;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL)
	return;

	changeBST(root, 0);
}
