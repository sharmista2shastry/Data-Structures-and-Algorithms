// Following is the Binary Tree node structure
/**************
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
***************/
#include <bits/stdc++.h>

void helper(BinaryTreeNode<int>* root, vector<int> temp, vector<int> &res, int height, int &maxheight)
{
    if(root == NULL)
    {
        if(height > maxheight)
        {
            maxheight = height;
            res = temp;
        }
    }

    else
    {
        temp.push_back(root->data);
        helper(root->left, temp, res, height+1, maxheight);
        helper(root->right, temp, res, height+1, maxheight);
    }
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    vector<int> res, temp;
    int maxheight = 0;
    helper(root, temp, res, 0, maxheight);
    vector<int> *ans = new vector<int>();
    reverse(res.begin(), res.end());
    *ans = res;
    return ans;
}
