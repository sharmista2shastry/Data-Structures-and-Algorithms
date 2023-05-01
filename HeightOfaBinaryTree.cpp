/***********************************************************
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

int height(BinaryTreeNode<int>* root) {
    // Write our code here
	if(root == NULL)
	return 0;

	if(root->left == NULL && root->right == NULL)
	return 1;

	int lh = height(root->left);
	int rh = height(root->right);

	return max(lh,rh) + 1;
}
