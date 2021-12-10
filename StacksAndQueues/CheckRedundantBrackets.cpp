/*
    For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
    A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

    Example:
    Expression: (a+b)+c
    Since there are no needless brackets, hence, the output must be 'false'.
    Expression: ((a+b))
    The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.

    Input Format :
    The first and the only line of input contains a string expression, without any spaces in between.

    Output Format :
    The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.

    Note:
    You are not required to print the expected result. It has already been taken care of.

    Constraints:
    0 <= N <= 10^6
    Where N is the length of the expression.
    Time Limit: 1 second

    Sample Input 1:
    a+(b)+c 
    Sample Output 1:
    true
    Explanation:
    The expression can be reduced to a+b+c. Hence, the brackets are redundant.

    Sample Input 2:
    (a+b)
    Sample Output 2:
    false
*/

// Iterate through the string and keep a count of useful
// characters between a '(' and ')'
// If the count is 0 or 1 then the brackets are reduntant
// else the brackets aren't reduntant

#include <stack>

bool checkRedundantBrackets(string expression) {
    stack<int> st;
    int count = 0;

    for(int i=0; i<expression.size(); i++) {
        if(expression[i] == '(') {
            st.push(expression[i]);
        }

        else if(expression[i] == ')') {
            while(st.top() != '(') {
                st.pop();
                count++;
            }
            // Pop the '('
            st.pop();
            
            if(count == 0 || count == 1) {
                // Redundant
                return true;
            }
            // Reset count to 0
            count = 0;
        }

        else {
            st.push(expression[i]);
        }
    }
    
    // Not redundant
    return false;
}