/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
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

***********************************************************/
void printAtDepthK(BinaryTreeNode<int> *root, int k)
{
        if(root == NULL)
        return;

        if(k == 0)
        cout << root->data << endl;

        printAtDepthK(root->left, k-1);
        printAtDepthK(root->right, k-1);
}

int helper(BinaryTreeNode<int> *root, int node, int k)
{
        if(root == NULL)
        return -1;

        if(root->data == node)
        {
            printAtDepthK(root, k);
            return 0;
        }

        int ld = helper(root->left, node, k);

        if(ld != -1)
        {
                if(ld + 1 == k)
                cout << root->data << endl;

                else
                printAtDepthK(root->right, k-ld-2);

                return ld + 1;
        }

        int rd = helper(root->right, node, k);

        if(rd != -1)
        {
                if(rd + 1 == k)
                cout << root->data << endl;

                else
                printAtDepthK(root->left, k-rd-2);

                return rd + 1;
        }
       
        return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    helper(root, node, k);
}
