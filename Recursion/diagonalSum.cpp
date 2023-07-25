#include <bits/stdc++.h> 
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

#include <vector>

vector < long long > diagonalSum(BinaryTreeNode < int >* root) {
    // Write your code here.
	vector<long long> list;
	queue<BinaryTreeNode <int>*> q;
	int sum = 0;
	int count = 0;
	int last = 0;

	while(root != NULL)
	{
		if(root->left)
		{
			q.push(root->left);
			count++;
		}
		
		sum += root->data;
		root = root->right;

		if(root == NULL)
		{
			if(!q.empty())
			{
				root = q.front();
				q.pop();
			}

			if(last == 0)
			{
				list.push_back(sum);
				last = count;
				count = 0;
				sum = 0;
			}

			last--;
		}
	}

	return list;
}
