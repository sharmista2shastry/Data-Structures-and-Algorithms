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

void helper(TreeNode<int>* root, int x, bool &res)
{
    if(root == NULL)
    {
        res = false;
        return;
    }

    if(root->data == x)
    {
        res = true;
        return;
    }

    for(int i=0; i<root->children.size(); i++)
    helper(root->children[i], x, res);
}

bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    bool res = false;
    
    helper(root, x, res);

    if(res == false)
    return false;

    else
    return true;
}
