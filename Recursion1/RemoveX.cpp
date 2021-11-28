/*
    Given a string, compute recursively a new string where all 'x' chars have been removed.

    Input format :
    String S

    Output format :
    Modified String

    Constraints :
    1 <= |S| <= 10^3
    where |S| represents the length of string S. 

    Sample Input 1 :
    xaxb
    Sample Output 1:
    ab

    Sample Input 2 :
    abc
    Sample Output 2:
    abc
    
    Sample Input 3 :
    xx
    Sample Output 3:
*/

#include <cstring>

void removeX(char input[]) {
    // Base case
    if(input[0] == '\0') {
        return;
    }

    // Recursive call
    removeX(input+1);
    
    // Check if the first character of the original string is 'x'
    if(input[0] == 'x') {
        // Shifting the array elements by 1 to remove 'x'
        for(int i=0; i<strlen(input); i++) {
            input[i] = input[i+1];
        }
    }
}