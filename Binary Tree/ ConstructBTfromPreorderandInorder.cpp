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

BinaryTreeNode<int> *helper(int *preorder, int *inorder, int pS, int pE, int iS, int iE, int pL, int iL)
{
	if(pS > pE || iS > iE)
	return NULL;

	int rootData = preorder[pS];
	int i;

	for(i = 0; i < iL; i++)
	{
		if(inorder[i] == rootData)
		break;
	}

	int LpS = pS + 1;
	int LiS = iS;
	int LiE = i - 1;
	int LpE = LiE - LiS + LpS;

	int RpS = LpE + 1;
	int RpE = pE;
	int RiS = i + 1;
	int RiE =iE;

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

	root->left = helper(preorder, inorder, LpS, LpE, LiS, LiE, pL, iL);
	root->right = helper(preorder, inorder, RpS, RpE, RiS, RiE, pL, iL);

	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	return helper(preorder,inorder,0,preLength-1,0,inLength-1,preLength,inLength);
}
