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
#include<stack>

void printZigZag(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL)
	return;

	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	BinaryTreeNode<int> *nextlevel = new BinaryTreeNode<int>(-1);
	q.push(nextlevel);
	bool flag = false;

	while(q.empty() == false)
	{
		BinaryTreeNode<int> *front = q.front();

		if(front->data != -1 && flag != true)
		q.pop();

		if(front->data != -1 && flag != true)
		cout << front->data;

		if(front->left != NULL && flag != true)
		q.push(front->left);

		if(front->right != NULL && flag != true)
		q.push(front->right);

		if(front->data == -1 && q.size() > 1 && flag == false)
		{
			q.pop();
			BinaryTreeNode<int> *next_level = new BinaryTreeNode<int>(-1);
			q.push(next_level);
			flag = true;
			cout << endl;
		}

		else if(flag == true)
		{
			BinaryTreeNode<int> *next_level = new BinaryTreeNode<int>(-1);

			stack <int>s;
			

			while(q.front()->data != -1)
			{
				BinaryTreeNode<int> *frontNode = q.front();
				s.push(frontNode->data);

				if(frontNode->left)
				q.push(frontNode->left);

				if(frontNode->right)
				q.push(frontNode->right);

				q.pop();

			}

			flag = false;

			while(s.empty() == false)
			{
				cout << s.top() << " ";
				s.pop();
			}

			q.pop();
			q.push(next_level);
			cout << endl;
		}

		else if(front->data == -1 && q.size() <= 1)
		q.pop();

		else if(front->data != -1)
		cout << " ";
	}
}

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL)
	return;

	printZigZag(root);
}
