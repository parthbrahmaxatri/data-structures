/*
    You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.

    Note: Don't print anything if there isn't any valid configuration.

    Input Format:
    The first line of input contains an integer, that denotes the value of N.     

    Output Format :
    In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.

    Constraints :
    1 <= N <= 10
    Time Limit: 1 second

    Sample Input 1:
    4
    Sample Output 1 :
    0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
    0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/

#include <iostream>
using namespace std;

void print(int **arr, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

bool isSafe(int **arr, int n, int row, int col) {
    // Checking if there is any other queen in the same column
    for(int i=row-1; i>=0; i--) {
        if(arr[i][col] == 1) {
            return false;
        }
    }
    
    // Checking if there is any other queen in the upper-left diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
        if(arr[i][j] == 1) {
            return false;
        }
    }
    
    // Checking if there is any other queen in the upper-right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
        if(arr[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

void nQueensHelper(int **arr, int n, int row) {
    // Base case
    if(n==row) {
        print(arr, n);
        return;
    }
    
    // Recursive call
    for(int col=0; col<n; col++) {
        if(isSafe(arr, n, row, col)) {
            arr[row][col] = 1;
            nQueensHelper(arr, n, row+1);
            arr[row][col] = 0;
        }
    }
}

void nQueens(int n) {
    // Creating a chessboard matrix
    int **arr = new int*[n];
    for(int i=0; i<n; i++) {
        arr[i] = new int[n];
    }
    
    // Initializing the chessboard matrix with 0
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = 0;
        }
    }
    
    nQueensHelper(arr, n, 0);
}

int main() {
    int n;
    cin >> n;
    
    nQueens(n);
    return 0;
}