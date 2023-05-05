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
#include<queue>

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    if(root == NULL)
    return false;

    int level = 0, level1 = -1, level2 = -1;
    queue<BinaryTreeNode<int>*> Q;
    Q.push(root);
    BinaryTreeNode<int> *new_level = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int> *node1;
    BinaryTreeNode<int> *node2;

    Q.push(new_level);

    while(Q.size() > 1)
    {
        BinaryTreeNode<int> *front = Q.front();
        Q.pop();

        if(front->left)
        Q.push(front->left);

        if(front->right)
        Q.push(front->right);

        if(front->data == -1)
        {
            level ++;
            BinaryTreeNode<int> *add_new_level = new BinaryTreeNode<int>(-1);
            Q.push(add_new_level);
        }
        
        if(front->left && front->right && front->left->data == p && front->right->data == q)
        return false;

        else if(front->left && front->right && front->left->data == q && front->right->data == p)
        return false;

        if(front->data == p)
        level1 = level;

        if(front->data == q)
        level2 = level;

        if(level1 == level2 && level1 != -1)
        return true;
    }

    return false;
}
