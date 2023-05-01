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
BinaryTreeNode<int> *helper(BinaryTreeNode<int>* root)
{
	if(root == NULL)
	return root;

	BinaryTreeNode<int> *right_child = helper(root->left);
	BinaryTreeNode<int> *left_child = helper(root->right);

	root->right = right_child;
	root->left = left_child;

	return root;
}
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
	helper(root);
}
