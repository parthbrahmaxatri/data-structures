/*
    You have been provided a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
    You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.

    Input Format:
    There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.

    Output Format:
    The first and only line of output contains boolean value, either true or false, as described in problem statement.

    Constraints:
    The cell values lie in the range: [0, 9]
    Time Limit: 1 second 

    Note:
    Input are given in a way that backtracking solution will work in the provided time limit.

    Sample Input 1:
    9 0 0 0 2 0 7 5 0 
    6 0 0 0 5 0 0 4 0 
    0 2 0 4 0 0 0 1 0 
    2 0 8 0 0 0 0 0 0 
    0 7 0 5 0 9 0 6 0 
    0 0 0 0 0 0 4 0 1 
    0 1 0 0 0 5 0 8 0 
    0 9 0 0 7 0 0 0 4 
    0 8 2 0 4 0 0 0 6
    Sample Output 1:
    true
*/

#include <iostream>
using namespace std;

bool isValid(int **arr, int x, int y, int val) {
    // Checking if val is already present in the same row
    for(int i=0; i<9; i++) {
        if(arr[x][i] == val) {
            return false;
        }
    }
    
    // Checking if val is already present in the same column
    for(int i=0; i<9; i++) {
        if(arr[i][y] == val) {
            return false;
        }
    }
    
    // Checking if val is already present in the small matrix
    // smI = small matrix I
    // smJ = small matrix J
    int smI = (x/3)*3;
    int smJ = (y/3)*3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(arr[smI+i][smJ+j] == val) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int **arr, int i, int j) {
    // Base case
    if(i == 9) {
        return true;
    }
    
    int nextI = 0, nextJ = 0;
    if(j == 8) {
        nextI = i+1;
        nextJ = 0;
    }
    else {
        nextI = i;
        nextJ = j+1;
    }

    if(arr[i][j] != 0) {
        // Recursive call
        if(sudokuSolver(arr, nextI, nextJ)) {
            return true;
        }
    }
    else {
        // po = possible option
        for(int po=1; po<=9; po++) {
            if(isValid(arr, i, j, po)) {
                arr[i][j] = po;
                
                // Recursive call
                bool temp = sudokuSolver(arr, nextI, nextJ);
                if(temp) {
                    return true;
                }
                
                arr[i][j] = 0;
            }
        }
        
        return false;
    }
}

int main() {
    // Creating an input matrix
    int **arr = new int*[9];
    for(int i=0; i<9; i++) {
        arr[i] = new int[9];
    }

    // Asking for values of the input matrix from user
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> arr[i][j];
        }
    }

    if (sudokuSolver(arr, 0, 0)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}