/*
    Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
    Input format :
    String S
    Output format :
    Modified string
    Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.
    Sample Input 1 :
    hello
    Sample Output 1:
    hel*lo
    Sample Input 2 :
    aaaa
    Sample Output 2 :
    a*a*a*a
*/

#include <cstring>

void pairStar(char input[]) {
    // Base case
    if(strlen(input)<=1) {
        return;
    }
    
    // Recursive call
    pairStar(input+1);
    
    // Check if first character of the original string and
    // first character of the string replaced by recursion
    // are identical
    if(input[0] == input[1]) {
        // Shifting the array elements by 1 to make some space for '*'
        for(int i=strlen(input); i>0; i--) {
            input[i+1] = input[i];
        }
        // Separating two identical characters by a '*'
        input[1] = '*';
    }
}