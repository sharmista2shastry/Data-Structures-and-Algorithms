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
void helper(BinaryTreeNode<int> *root, int k, vector<int> arr, int sum)
{
	if(root == NULL)
	return;

	if(root->left == NULL && root->right == NULL)
	{
		if(sum == k)
		{
			for(int i=0; i<arr.size(); i++)
			cout << arr[i] << " ";

			cout << endl;
		} 
		return;
	}

	if(root->left)
	{
		arr.push_back(root->left->data);
		sum += root->left->data;
	
		helper(root->left, k, arr, sum);

		sum -= root->left->data;
		arr.pop_back();
	}

	if(root->right)
	{
		arr.push_back(root->right->data);
		sum += root->right->data;

		helper(root->right, k, arr, sum);
	}
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
	int sum = root->data;
	vector<int> arr;
	arr.push_back(root->data);
	helper(root, k, arr, sum);
}
