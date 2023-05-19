//Time Complexity: O(4^N), where N is the total number of cells in the maze
//Space Complexity: O(N^2),where N is the total number of rows or columns in an NxN matrix

/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

//Checking if it is possible to go in a certain direction in the maze

bool isSafe(int sol[19][19], int maze[19][19], int row, int col, int n)
{
	if(row < 0 && row >= n && col < 0 && col >= n)
	return false;

	if(maze[row][col] == 0)
	return false;

	if(sol[row][col] == 1)
	return false;

	return true;
}

void mazePath(int sol[19][19], int maze[19][19], int row, int col, int n)
{
  // We have reached the destination cell
  //Print the solution and return
  
	if(row == n-1 && col == n-1)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << sol[i][j] <<" ";
			}
		}
		cout << endl;
		return;
	}
  
  //Exploring Possible Paths and Backtracking

	if(isSafe(sol, maze, row, col-1, n))
	{
		sol[row][col-1] = 1;
		mazePath(sol, maze, row, col-1, n);
		sol[row][col-1] = 0;
	}

	if(isSafe(sol, maze, row, col+1, n))
	{
		sol[row][col+1] = 1;
		mazePath(sol, maze, row, col+1, n);
		sol[row][col+1] = 0;
	}

	if(isSafe(sol, maze, row-1, col, n))
	{
		sol[row-1][col] = 1;
		mazePath(sol, maze, row-1, col, n);
		sol[row-1][col] = 0;
	}
	
	if(isSafe(sol, maze, row+1, col, n))
	{
		sol[row+1][col] = 1;
		mazePath(sol, maze, row+1, col, n);
		sol[row+1][col] = 0;
	}
}

int main() {
	// Write your code here
	int maze[19][19], sol[19][19];
	int n;

	cin >> n;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> maze[i][j];
			sol[i][j] = 0;
		}
	}

	sol[0][0] = 1;
	mazePath(sol, maze, 0, 0, n);

	return 0;
}
