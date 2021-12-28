/*
    An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
    From a cell (i, j), you can move in three directions:
    1. ((i + 1),  j) which is, "down"
    2. (i, (j + 1)) which is, "to the right"
    3. ((i+1), (j+1)) which is, "to the diagonal"
    The cost of a path is defined as the sum of each cell's values through which the route passes.
*/

#include <algorithm>

int minCostPathHelper(int **input, int rows, int cols, int **dp) {
    
    // Save min cost path to reach cell[rows-1][cols-1] from cell[i][j] at dp[i][j]
    for(int i=rows-1; i>=0; i--) {
        for(int j=cols-1; j>=0; j--) {
            if(i==rows-1 && j==cols-1) {
                dp[i][j] = input[i][j];
            }
            else if(i==rows-1) {
                dp[i][j] = input[i][j] + dp[i][j+1];
            }
            else if(j==cols-1) {
                dp[i][j] = input[i][j] + dp[i+1][j];
            }
            else {
                dp[i][j] = input[i][j] + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
            }
        }
    }
    
    return dp[0][0];
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

    return minCostPathHelper(input, m, n, dp);
}