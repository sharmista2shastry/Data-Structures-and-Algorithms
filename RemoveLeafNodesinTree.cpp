// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};
***************/

TreeNode<int>* helper(TreeNode<int>*root)
{
	if(root==NULL)
	{
         return NULL;
     }

    if(root->numChildren()==0)
	{
        delete root;
        return NULL;
    }

    for(int i=0;i<root->numChildren();i++)
	{
        TreeNode<int>*child=root->getChild(i);
		
         if(child->numChildren()==0)
		 {
              root->removeChild(i);
			  i--;
          }
		  else
		  {
             root->setChild(i,helper(child));
         }
    }
   
    return root;
}

TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    // Write your code here
	if(root->numChildren() == 0)
	return root;

	return helper(root);
}
