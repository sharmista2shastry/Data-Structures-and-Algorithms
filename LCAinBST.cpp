int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
	if(root == NULL)
	return -1;

	if(root->data == val1 || root->data == val2)
	return root->data;

	if((val1 < root->data && val2 > root->data) || (val2 < root->data && val1 > root->data))
	return root->data;

	if(root->data > val1 && root->data > val2)
	return getLCA(root->left, val1, val2);

	if(root->data < val1 && root->data < val2)
	return getLCA(root->right, val1, val2);
}
