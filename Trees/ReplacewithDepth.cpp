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
void helper(TreeNode<int>* root, int level)
{
    if(root == NULL)
    return;

    root->data = level;
    level++;

    for(int i=0; i<root->children.size(); i++)
    {
        helper(root->children[i], level);
    }

    return;
}

void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL)
    return;

    helper(root, 0);

    return;
}
