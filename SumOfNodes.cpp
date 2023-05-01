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
void helper(BinaryTreeNode<int>* root, int &sum)
{
	if(root == NULL)
	return;

	sum += root->data;

	helper(root->left, sum);
	helper(root->right, sum);

	return;
}

int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
	if(root == NULL)
	return 0;

	int sum = 0;

	helper(root, sum);

	return sum;
}
