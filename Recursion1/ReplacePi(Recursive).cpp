/*
    Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

    Constraints :
    1 <= |S| <= 50
    where |S| represents the length of string S. 

    Sample Input 1 :
    xpix
    Sample Output :
    x3.14x

    Sample Input 2 :
    pipi
    Sample Output :
    3.143.14

    Sample Input 3 :
    pip
    Sample Output :
    3.14p
*/

#include <cstring>

void replacePi(char input[]) {
    // Base case
    if(input[0]=='\0') {
        return;
    }
    
    // Recursive call
    replacePi(input+1);
    
    // Check if first character of the original string and
    // first character of the string replaced by recursion
    // are 'p' and 'i' respectively
    if(input[0]=='p' && input[1]=='i') {
        // Shifting the array elements by 2 to make some space for '14'
        for(int i=strlen(input); i>1; i--) {
            input[i+2] = input[i];
        }
        // Replacing 'pi' by '3.14'
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}