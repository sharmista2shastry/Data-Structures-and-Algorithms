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

	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	BinaryTreeNode<int> *nextlevel = new BinaryTreeNode<int>(-1);
	q.push(nextlevel);

	while(q.empty() == false)
	{
		BinaryTreeNode<int> *front = q.front();

		if(front->data != -1)
		q.pop();

		if(front->data != -1)
		cout << front->data;

		if(front->left != NULL)
		q.push(front->left);

		if(front->right != NULL)
		q.push(front->right);

		if(front->data == -1 && q.size() > 1)
		{
			q.pop();
			BinaryTreeNode<int> *next_level = new BinaryTreeNode<int>(-1);
			q.push(next_level);
			cout << endl;
		}

		else if(front->data == -1 && q.size() <= 1)
		q.pop();

		else if(front->data != -1)
		cout << " ";
	}
}
