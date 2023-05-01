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
BinaryTreeNode<int>* helper(BinaryTreeNode<int> *root)
{
	if(root == NULL)
	return NULL;

	if(root->left == NULL && root->right == NULL)
	{
		BinaryTreeNode<int> *temp = root;
		delete temp;
		return NULL;
	}

	root->left = helper(root->left);
	root->right = helper(root->right);

	return root;
}


BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL || (root->left == NULL && root->right == NULL))
	return NULL;

	return helper(root);
}
