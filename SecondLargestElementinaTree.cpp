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
#include<climits>

void helper(TreeNode<int>* root, int &max, int &sec_max, TreeNode<int> **maxNode, TreeNode<int> **sec_maxNode)
{
    if(root == NULL)
    return;

    if(*maxNode == NULL)
    {
        max = root->data;
        *maxNode = root;
    }

    if(root->data > max)
    {
        sec_max = max;
        *sec_maxNode = *maxNode;
        max = root->data;
        *maxNode = root;
    }

    else if(!(*sec_maxNode))
    {
        if(root->data < (*maxNode)->data)
        {
            sec_max = root->data;
            *sec_maxNode = root;
        }
    }

    for(int i=0; i < root->children.size(); i++)
    helper(root->children[i],max,sec_max, maxNode, sec_maxNode);
}


TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL)
    return root;

    int max = INT_MIN;
    int sec_max = INT_MIN;
    TreeNode<int> *maxNode = NULL, *sec_maxNode = NULL;

    helper(root, max, sec_max, &maxNode, &sec_maxNode);

    if(sec_max == INT_MIN)
    return NULL;

    return sec_maxNode;
}
