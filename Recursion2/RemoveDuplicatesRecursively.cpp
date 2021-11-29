/*
    Given a string S, remove consecutive duplicates from it recursively.

    Input Format :
    String S

    Output Format :
    Output string
    
    Constraints :
    1 <= |S| <= 10^3
    where |S| represents the length of string

    Sample Input 1 :
    aabccba
    Sample Output 1 :
    abcba
    
    Sample Input 2 :
    xxxyyyzwwzzz
    Sample Output 2 :
    xyzwz
*/

#include <cstring>

void removeConsecutiveDuplicates(char *input) {
    // Base case
    if(strlen(input)==1) {
        return;
    }
    
    // Recursive call
    removeConsecutiveDuplicates(input+1);
    
    // Check if the first two characters are duplicate
    if(input[0]==input[1]) {
        int i;
        // Shifting the array elements by 1
        for(i=1; i<strlen(input); i++) {
            input[i-1] = input[i];
        }
        input[i-1] = input[i];
    }
}