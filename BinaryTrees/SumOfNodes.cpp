/*
    For a given Binary Tree of integers, find and return the sum of all the nodes data.

    Input Format:
    The first and the only line of input will contain the nodes data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

    Output Format:
    The first and the only line of output prints the sum of all the nodes data present in the binary tree.

    Note:
    You are not required to print anything explicitly. It has already been taken care of.

    Constraints:
    1 <= N <= 10^6
    Where N is the total number of nodes in the binary tree.
    Time Limit: 1 sec

    Sample Input 1:
    2 3 4 6 -1 -1 -1 -1 -1
    Sample Output 1:
    15

    Sample Input 2:
    1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    Sample Output 2:
    28
 */

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

int getSum(BinaryTreeNode<int>* root) {
    // Base case
    if(root==NULL) {
        return 0;
    }
    
    int sum = root->data;
    
    // Recursive call
    int leftSum = getSum(root->left);
    
    // Recursive call
    int rightSum = getSum(root->right);
    
    return sum + leftSum + rightSum;
}