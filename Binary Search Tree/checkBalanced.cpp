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

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL)
	return true;

	if(root->left == NULL && root->right == NULL)
	return true;

	if(root->left == NULL && root->right != NULL)
	return false;

	else if(root->left != NULL && root->right == NULL)
	return false;

	return isBalanced(root->left) && isBalanced(root->right);
}
