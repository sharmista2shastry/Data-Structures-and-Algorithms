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
/* Following will return TLE as time complexity is O(n^2):

#include<climits>

bool findNode(BinaryTreeNode<int> *root, int data)
{
	if(root == NULL)
	return false;

	if(root->data == data)
	{
		root->data = INT_MIN;
		return true;
	}

	return findNode(root->left, data) || findNode(root->right, data);
}


void helper(BinaryTreeNode<int> *root, BinaryTreeNode<int> *temp, int sum) {
    // Write your code here
	if(temp == NULL)
	return;

	if(temp->data < sum && temp->data != INT_MIN)
	{
		int diff = sum - temp->data;
		int ans = temp->data;
		temp->data = INT_MIN;

		bool res = findNode(root, diff);

                if(res) 
				{
                  if (diff < ans)
                    cout << diff << " " << ans;

                  else
                    cout << ans << " " << diff;

                  cout << endl;
                }
     }  
	
	helper(root, temp->left, sum);
    helper(root, temp->right, sum);
}

void pairSum(BinaryTreeNode<int> *root, int sum)
{
	helper(root, root, sum);
}

Optimised approach: */

#include<bits/stdc++.h>

void convertToArr(BinaryTreeNode<int> *root, vector<int> &arr)
{
	if(root == NULL)
	return;

	arr.push_back(root->data);

	convertToArr(root->left, arr);
	convertToArr(root->right, arr);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	vector<int> arr;

	convertToArr(root, arr);

	int n = arr.size();

	sort(arr.begin(), arr.end());

	int i = 0 , j = n - 1;

	while(i < j)
	{
		if(arr[i] + arr[j] == sum)
		{
			cout << arr[i] << " " << arr[j] << endl;
			i++;
			j--;
		}

		else if(arr[i] + arr[j] < sum)
		i++;

		else
		j--;
	}
}

