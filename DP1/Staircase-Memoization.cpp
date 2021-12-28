/*
    A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
*/

int staircaseHelper(int n, int *dp){   
    // Base case
    if(n<0) {
        return 0;
    }
    // There is a path from zero to zero
    // Do nothing - stand there
    if(n==0) {
        return 1;
    }
    
    // Check if answer already exists
    if(dp[n] != -1) {
        return dp[n];
    }
    
    // Recursive calls
    int x = staircaseHelper(n-1, dp);
    int y = staircaseHelper(n-2, dp);
    int z = staircaseHelper(n-3, dp);
    
    // Save answer for future use
    int ans = x+y+z;
    dp[n] = ans;
    
    return dp[n];
}

int staircase(int n){
    int *dp = new int[n+1];
    for(int i=0; i<=n; i++) {
        dp[i] = -1;
    }
    
    return staircaseHelper(n, dp);
}