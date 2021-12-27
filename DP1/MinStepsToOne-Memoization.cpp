/*
    Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
    1.) Subtract 1 from it. (n = n - ­1) ,
    2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
    3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
*/

#include <climits>
#include <algorithm>

int countMinStepsToOneHelper(int n, int *dp) {
    // Base case
    if(n<=1) {
        return 0;
    }
    
    // Check if answer already exists
    if(dp[n] != -1) {
        return dp[n];
    }
    
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    
    // Recursive call
    x = countMinStepsToOneHelper(n-1, dp);
    
    // Recursive call
    if(n%2 == 0) {
        y = countMinStepsToOneHelper(n/2, dp);
    }
    
    // Recursive call
    if(n%3 == 0) {
        z = countMinStepsToOneHelper(n/3, dp);
    }
    
    int ans = min(x, min(y, z)) + 1;

    // Save answer for future use
    dp[n] = ans;
    
    return dp[n];
}

int countMinStepsToOne(int n) {
    int *dp = new int[n+1];
    for(int i=0; i<=n; i++) {
        dp[i] = -1;
    }
    
    return countMinStepsToOneHelper(n, dp);
}