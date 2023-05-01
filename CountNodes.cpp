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
void helper(TreeNode<int>* root, int x, int &count)
{
    if(root == NULL)
    return;

    if(root->data > x)
        count++;

    for(int i=0; i < root->children.size(); i++)
    helper(root->children[i], x, count);
}

int getLargeNodeCount(TreeNode<int>* root, int x) {
    // Write your code here
    int count = 0;
    helper(root, x, count);

    return count;
}
