/*
    Check whether a given String S is a palindrome using recursion. Return true or false.

    Input Format :
    String S

    Output Format :
    'true' or 'false'
    
    Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.

    Sample Input 1 :
    racecar
    Sample Output 1:
    true
    
    Sample Input 2 :
    ninja
    Sample Output 2:
    false
*/

#include <cstring>

bool checkPalindromeHelper(char input[], int startIndex, int endIndex) {
    // Base case
    if(startIndex>=endIndex) {
        return true;
    }
    
    // Stop right now itself if the string isn't palindrome
    if(input[startIndex]!=input[endIndex]) {
        return false;
    }
    
    // Check for the remaining string
    bool smallAns = checkPalindromeHelper(input, startIndex+1, endIndex-1);
    return smallAns;
}

bool checkPalindrome(char input[]) {
    // Create a helper function as changing the existing function isn't allowed
    return checkPalindromeHelper(input, 0, strlen(input)-1);
}