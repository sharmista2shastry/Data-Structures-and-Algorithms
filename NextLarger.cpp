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
#include <climits>

void helper(TreeNode<int>* root, int x, int &min, TreeNode<int> **res)
{
    if(root == NULL)
    return;

    if(root->data > x && root->data < min)
    {
        min = root->data;
        *res = root;
    }

    for(int i=0; i<root->children.size(); i++)
    helper(root->children[i], x, min, res);

    return;
}


TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here

    if(root == NULL)
    return root;

    TreeNode<int> *res; 
    int min = INT_MAX;

    helper(root, x, min, &res);

    return res;

}
