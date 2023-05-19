//Time Complexity: The time complexity of the code is exponential, specifically O(9^(n^2)), where n is the size of the Sudoku grid (in this case, n = 9)
//Space Complexity: The space complexity of the code is O(1) because it uses a fixed-size 2D array grid[9][9] to represent the Sudoku grid, and the other variables used in the code are of constant size.

#include<bits/stdc++.h>
using namespace std;

//Find any available empty spaces in the sudoku

bool findEmptySpaces(int grid[9][9], int &row, int &col)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

//Check if the number can be inserted in a particular space

bool isRowSafe(int grid[9][9], int row, int num)
{
    for(int j=0; j<9; j++)
    {
        if(grid[row][j] == num)
        return false;
    }
    return true;
}

bool isColSafe(int grid[9][9], int col, int num)
{
    for(int i=0; i<9; i++)
    {
        if(grid[i][col] == num)
        return false;
    }
    return true;
}

bool isGridSafe(int grid[9][9], int row, int col, int num)
{
    int rowFactor = row - (row%3);
    int colFactor = col - (col % 3);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(grid[i+rowFactor][j+colFactor] == num)
            return false;
        }
    }
    return true;
}

bool isSafe(int grid[9][9], int row, int col, int num)
{
    return (isRowSafe(grid, row, num) && isColSafe(grid, col, num) && isGridSafe(grid, row, col, num));
}

bool sudokuSolver(int grid[9][9])
{
    int row, col;
  
    //if all the spaces have been filled, it means we have solved our sudoku puzzle

    if(!findEmptySpaces(grid, row, col))
    return true;
  
    //Check for all numbers from 1 to 9

    for(int i=1; i<=9; i++)
    {
        if(isSafe(grid, row, col, i))
        {
            grid[row][col] = i;

            if(sudokuSolver(grid))
            return true;
          
            //Backtrack if the number did not lead us to a solution

            grid[row][col] = 0;
        }
    }

    return false;
}

int main(){
    // write your code here
    int grid[9][9];

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin >> grid[i][j];
        }
    }

    if(sudokuSolver(grid))
    cout << "true" << endl;

    else
    cout << "false" << endl;

    return 0;
}
