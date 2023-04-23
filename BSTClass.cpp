/**********************************************************
	Following is the Binary Tree Node class structure
	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;
    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include<climits>

class BST {
    // Define the data members
    BinaryTreeNode<int> *root;

    bool search(BinaryTreeNode<int> *root, int data)
    {
        if(root == NULL)
        return false;

        if(root->data == data)
        return true;

        if(root->data > data)
        search(root->left, data);

        else if(root->data < data)
        search(root->right, data);
    }

    void print(BinaryTreeNode<int> *root)
    {
        if(root == NULL)
        return;

        cout << root->data <<":";
        if(root->left != NULL)
        cout <<"L:"<<root->left->data<<",";
        if(root->right != NULL)
        cout<<"R:"<<root->right->data<<endl;
        else
        cout<<endl;

        print(root->left);
        print(root->right);
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int> *root, int data)
    {
        if(root == NULL)
        {
            BinaryTreeNode<int> *new_node = new BinaryTreeNode<int>(data);
            return new_node;
        }

        if(root->data >= data)
        root->left = insert(root->left, data);

        else if(root->data < data)
        root->right = insert(root->right, data);

        return root;
    }

    BinaryTreeNode<int>* remove(BinaryTreeNode<int> *root, int data)
    {
        if(root == NULL)
        return NULL;

        if(root->data > data)
        {
            root->left = remove(root->left, data);
            return root;
        }

        else if(root->data < data)
        {
            root->right = remove(root->right, data);
            return root;
        }
        
        else
        {
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            else if(root->left == NULL && root->right != NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                delete root;
                return temp;
            }

            else if(root->left != NULL && root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                delete root;
                return temp;
            }

            else
            {
                BinaryTreeNode<int> *minNode = root->right;
                
                while(minNode->left != NULL)
                minNode = minNode->left;

                root->data = minNode->data;
                root->right = remove(root->right, minNode->data);

                return root;
            }
        }
    }

   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
        root = remove(root, data);
    }

    void print() { 
        // Implement the print() function
        print(root);
    }

    void insert(int data) { 
        // Implement the insert() function 
        root = insert(root, data);
    }

    bool search(int data) {
		// Implement the search() function 
        return search(root, data);
    }
};
