/*
    You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
    Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
    1. Delete a character
    2. Replace a character with another one
    3. Insert a character

    Input format :
    The first line of input contains the string S of length M.
    The second line of the input contains the String T of length N.

    Output format :
    Print the minimum 'Edit Distance' between the strings.

    Constraints :
    0 <= M <= 10 ^ 3
    0 <= N <= 10 ^ 3
    Time Limit: 1 sec

    Sample Input 1 :
    abc
    dc
    Sample Output 1 :
    2
    Explanation to the Sample Input 1 :
    In 2 operations we can make string T to look like string S.
    First, insert character 'a' to string T, which makes it "adc".
    And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 
    Hence, the minimum distance.

    Sample Input 2 :
    whgtdwhgtdg
    aswcfg
    Sample Output 2 :
    9
*/

int editDistanceHelper(string s1, string s2, int **dp) {
    int m = s1.size();
    int n = s2.size();
    
    // Base case
    if(s1.size() == 0 || s2.size() == 0) {
        return max(s1.size(), s2.size());
    }
    
    // Check if answer already exists
    if(dp[m][n] != -1) {
        return dp[m][n];
    }
    
    if(s1[0] == s2[0]) {
        return editDistanceHelper(s1.substr(1), s2.substr(1), dp);
    }
    
    // Recursive call - Insert
    int x = editDistanceHelper(s1.substr(1), s2, dp) + 1;
    
    // Recursive call - Delete
    int y = editDistanceHelper(s1, s2.substr(1), dp) + 1;
    
    // Recursive call - Replace
    int z = editDistanceHelper(s1.substr(1), s2.substr(1), dp) + 1;
    
    // Save answer for future use
    int answer = min(x, min(y, z));
    dp[m][n] = answer;
    
    return dp[m][n];
}

int editDistance(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    
    int **dp = new int*[m];
    for(int i=0; i<=m; i++) {
        dp[i] = new int[n+1];
    }
    
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            dp[i][j] = -1;
        }
    }
    
    return editDistanceHelper(s1, s2, dp);
}