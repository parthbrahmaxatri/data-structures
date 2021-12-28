/*
    An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
    From a cell (i, j), you can move in three directions:
    1. ((i + 1),  j) which is, "down"
    2. (i, (j + 1)) which is, "to the right"
    3. ((i+1), (j+1)) which is, "to the diagonal"
    The cost of a path is defined as the sum of each cell's values through which the route passes.
*/

#include <algorithm>

int minCostPathHelper(int **input, int rows, int cols, int **dp, int x, int y) {
    // Base case
    if(x==rows-1 && y==cols-1) {
        return input[x][y];
    }
    if(x==rows-1) {
        return input[x][y] + minCostPathHelper(input, rows, cols, dp, x, y+1);
    }
    if(y==cols-1) {
        return input[x][y] + minCostPathHelper(input, rows, cols, dp, x+1, y);
    }

    // Check if answer already exists
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    
    // Recursive calls
    int a = minCostPathHelper(input, rows, cols, dp, x, y+1);
    int b = minCostPathHelper(input, rows, cols, dp, x+1, y);
    int c = minCostPathHelper(input, rows, cols, dp, x+1, y+1);
    
    // Save answer for future use
    int answer = input[x][y] + min(a, min(b, c));
    dp[x][y] = answer;

    return dp[x][y];
}

int minCostPath(int **input, int m, int n) {
    int **dp = new int*[m];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            dp[i] = new int[n];
        }
    }
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = -1;
        }
    }

    return minCostPathHelper(input, m, n, dp, 0, 0);
}