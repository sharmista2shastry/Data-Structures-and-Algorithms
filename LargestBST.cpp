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
	
***********************************************************/
#include<bits/stdc++.h>

pair<bool,int> isBST(BinaryTreeNode<int> *root, int min, int maximum)
{
	if(root == NULL)
	{
		pair<bool,int> p;
		p.first = true;
		p.second = 0;
		return p;
	}

	if(root->data < min || root->data > maximum)
	{
		pair<bool,int> p;
		p.first = false;
		p.second = 0;
		return p;
	}

	pair<bool, int> pL = isBST(root->left,min,root->data-1);
	pair<bool, int> pR = isBST(root->right, root->data+1, maximum);

	pair<bool, int> p;
	p.first = pL.first && pR.first;
	p.second = max(pL.second, pR.second) + 1;

	return p;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL)
	return 0;

	int min = INT_MIN;
	int maximum = INT_MAX;

	pair<bool, int> res = isBST(root, min, maximum);

	if(res.first)
	return res.second;

	else
	return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
}
