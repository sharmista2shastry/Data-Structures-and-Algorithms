/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/

#include<climits>

void helper(BinaryTreeNode<int> *root, int &max, int &min){

if(root == NULL)
	return;

	if(root->data > max)
	max = root->data;

	if(root->data < min)
	min = root->data;

	helper(root->left, max, min);
	helper(root->right, max, min);

	return;
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL)
	{
		pair <int,int> p;
		p.first = 0;
		p.second = 0;
	}

	int max = INT_MIN;
	int min = INT_MAX;

	helper(root, max, min);

	pair <int,int> p;
	p.first = min;
	p.second = max;

	return p;
}
