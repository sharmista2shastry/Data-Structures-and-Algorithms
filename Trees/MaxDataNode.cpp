/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include<bits/stdc++.h>

TreeNode<int> *helper(TreeNode<int>* root, TreeNode<int> *maxNode, int &max)
{
    if(root->data > max)
    {
        max = root->data;
        maxNode = root;
    }

    for(int i=0; i<root->children.size(); i++)
    helper(root->children[i],maxNode, max);

    return maxNode;
}


TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    return helper(root, root, root->data);
}
