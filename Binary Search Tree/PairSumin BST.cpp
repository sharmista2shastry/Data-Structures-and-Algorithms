#include <stack>

int countNodes(BinaryTreeNode<int> *root)
{
	if(root == NULL)
	return 0;

	return countNodes(root->left) + countNodes(root->right) + 1;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
	if(root == NULL)
	return;

	int count = 0;
	int totalCount = countNodes(root);

	stack<BinaryTreeNode<int> *> inorder;
	stack<BinaryTreeNode<int> *> revInorder;

	BinaryTreeNode<int> *curr = root;

	while(curr)
	{
		inorder.push(curr);
		curr = curr->left;
	}

	curr = root;

	while(curr)
	{
		revInorder.push(curr);
		curr = curr->right;
	}

	while(count < totalCount - 1)
	{
		BinaryTreeNode<int> *inorderTop = inorder.top();
		BinaryTreeNode<int> *revInorderTop = revInorder.top();

		if(inorderTop->data + revInorderTop->data == s)
		{
			cout << inorderTop->data << " " << revInorderTop->data << endl;
			BinaryTreeNode<int> *top = inorderTop;

			inorder.pop();
			count++;

			if(top->right)
			{
				top = top->right;

				while(top)
				{
					inorder.push(top);
					top = top->left;
				}
			}
			
			top = revInorderTop;
			revInorder.pop();
			count++;

			if(top->left)
			{
				top = top->left;

				while(top)
				{
					revInorder.push(top);
					top = top->right;
				}
			}
		}

		else if(inorderTop->data + revInorderTop->data > s)
		{
			BinaryTreeNode<int> *top = revInorderTop;
			revInorder.pop();
			count++;

			if(top->left)
			{
				top = top->left;

				while(top)
				{
					revInorder.push(top);
					top = top->right;
				}
			}			
		}

		else
		{
			BinaryTreeNode<int> *top = inorderTop;
			inorder.pop();
			count++;

			if(top->right)
			{
				top = top->right;

				while(top)
				{
					inorder.push(top);
					top = top->left;
				}
			}
		}
	}
}
