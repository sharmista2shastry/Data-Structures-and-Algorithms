/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
    return;

    BinaryTreeNode<int> *temp = NULL;

    if(root->left)
    temp = root->left;

    BinaryTreeNode<int> *copy = new BinaryTreeNode<int>(root->data);

    root->left = copy;

    if(temp)
    copy->left = temp;

    if(temp)
    insertDuplicateNode(temp);

    insertDuplicateNode(root->right);    
}
