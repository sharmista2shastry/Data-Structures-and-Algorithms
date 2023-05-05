int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
	if(root == NULL)
	return -1;

	if(root->data == a || root->data == b)
	return root->data;

	int leftLCA = getLCA(root->left, a, b);
	int rightLCA = getLCA(root->right, a, b);

	if(leftLCA == -1 && rightLCA == -1)
	return -1;

	else if(leftLCA == -1 && rightLCA != -1)
	return rightLCA;

	else if(leftLCA != -1 && rightLCA == -1)
	return leftLCA;

	else
	return root->data;
}
