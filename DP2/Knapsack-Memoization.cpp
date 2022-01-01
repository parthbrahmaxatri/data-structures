/*
    A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
    
    Input Format :
    The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.

    Output Format :
    The first and only line of output contains the maximum value that thief can generate, as described in the task. 

    Constraints
    1 <= N <= 10^4
    1<= wi <= 100
    1 <= vi <= 100
    Time Limit: 1 second

    Sample Input 1 :
    4
    1 2 4 5
    5 4 8 6
    5
    Sample Output 1 :
    13
*/

// TIME COMPLEXITY: O(n*maxWeight)
// SPACE COMPLEXITY: O(n*maxWeight)

int knapsackHelper(int* weight, int* value, int n, int maxWeight, int **dp) {
    // Base case
    if(n==0 || maxWeight==0) {
        return 0;
    }
    
    // Check if output already exists
    if(dp[n][maxWeight] != -1) {
        return dp[n][maxWeight];
    }
    
    if(weight[0] > maxWeight) {
        // Save answer for future use
        int answer = knapsackHelper(weight+1, value+1, n-1, maxWeight, dp);
        dp[n][maxWeight] = answer;
        
        return dp[n][maxWeight];
    }
    
    // Recursive call - Consider the current item
    int x = knapsackHelper(weight+1, value+1, n-1, maxWeight-weight[0], dp) + value[0];
    
    // Recursive call - Don't consider the current item
    int y = knapsackHelper(weight+1, value+1, n-1, maxWeight, dp);
    
    // Save answer for future use
    int answer = max(x, y);
    dp[n][maxWeight] = answer;
    
    return dp[n][maxWeight];
}

int knapsack(int* weight, int* value, int n, int maxWeight) {        
    int **dp = new int*[n+1];
    for(int i=0; i<=n; i++) {
        dp[i] = new int[maxWeight+1];
    }
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=maxWeight; j++) {
            dp[i][j] = -1;
        }
    }
    
	return knapsackHelper(weight, value, n, maxWeight, dp);
}