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
#include<queue>

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL)
	return;

	queue<BinaryTreeNode<int> *> q;
	q.push(root);

	while(q.empty() == false)
	{
		BinaryTreeNode<int> *front = q.front();
		q.pop();

		if(front != NULL)
		cout << front->data<<":";

		if(front->left != NULL)
		{
			q.push(front->left);
			cout << "L:" << front->left->data<<",";
		}

		else if(front->left == NULL)
		cout << "L:" << "-1,";

		if(front->right != NULL)
		{
			q.push(front->right);
			cout << "R:" << front->right->data;
		}
		
		else if(front->right == NULL)
		cout << "R:" << "-1";

		cout << endl;	
	}
}
