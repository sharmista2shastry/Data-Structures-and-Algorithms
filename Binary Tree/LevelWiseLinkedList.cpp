/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/
#include<queue>
#include <vector>

vector<Node<int>*> printLevelWise(BinaryTreeNode<int> *root, vector<Node<int>*> arr) {
    // Write your code here
	if(root == NULL)
	return arr;

	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	BinaryTreeNode<int> *nextlevel = new BinaryTreeNode<int>(-1);
	q.push(nextlevel);
	Node<int> *head = NULL, *temp = NULL;
	int i = 0;

	while(q.empty() == false)
	{
		BinaryTreeNode<int> *front = q.front();

		if(front->data != -1)
		q.pop();

		if(front->data != -1)
		{
			if(head == NULL)
			{
				Node<int> *frontNode = new Node<int>(front->data);
				head = frontNode;
				temp = frontNode;
			}

			else
			{
				temp->next = new Node<int> (front->data);
				temp = temp->next;
			}
		}

		if(front->left != NULL)
		q.push(front->left);

		if(front->right != NULL)
		q.push(front->right);

		if(front->data == -1 && q.size() > 1)
		{
			q.pop();
			BinaryTreeNode<int> *next_level = new BinaryTreeNode<int>(-1);
			q.push(next_level);
			arr.push_back(head);
			head = NULL;
			temp = NULL;
		}

		else if(front->data == -1 && q.size() <= 1)
		{
			arr.push_back(head);
			q.pop();
		}
	}

	return arr;
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	vector<Node<int>*> arr;

	if(root == NULL)
	return arr;

	return printLevelWise(root, arr);
}
