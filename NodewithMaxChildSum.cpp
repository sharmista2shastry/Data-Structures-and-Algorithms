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
void helper(TreeNode<int>* root, int &max_sum, TreeNode<int> **res)
{
    if (root == NULL)
        return;
        
    int sum = root->data;

    for(int i=0; i<root->children.size(); i++)
    {
        sum += root->children[i]->data;
        helper(root->children[i], max_sum, res);
    }
    
    if(sum > max_sum)
    {
        max_sum = sum;
        *res = root;
    }

    return;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL)
    return root;

    TreeNode<int> *res;
    int max_sum = 0;
    
    helper(root, max_sum, &res);

    return res;
}
