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
#include<queue>

void printLevelWise(TreeNode<int>* root) {
    if(root == NULL)
    return;
    // Write your code here
    queue<TreeNode<int>*> q;
    q.push(root);

    while(q.empty() != true)
    {
        TreeNode<int> *front = q.front();
        cout << front->data << ":";
        q.pop();
        for(int i=0; i<front->children.size(); i++)
        {
            if(i == front->children.size()-1)
            cout << front->children[i]->data;
            else
            cout << front->children[i]->data << ",";
            q.push(front->children[i]);
        }
        cout << endl;
    }
}
