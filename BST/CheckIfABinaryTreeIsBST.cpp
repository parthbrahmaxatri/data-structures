/*
    Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.

    Note: Duplicate elements should be kept in the right subtree.

    Input format :
    The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

    Output format :
    The first and only line of output contains either true or false.

    Constraints :
    Time Limit: 1 second
    
    Sample Input 1 :
    3 1 5 -1 2 -1 -1 -1 -1
    Sample Output 1 :
    true
    
    Sample Input 2 :
    5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
    Sample Output 2 :
    false
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

// 1. All the elements on the left of the root of the binary tree should be smaller than the root element
// 2. All the elements on the right of the root of the binary tree should be greater than/equal to the root element
// 3. Left subtree should be a BST
// 4. Right subtree should be a BST

#include <algorithm>
#include <climits>

int minimum(BinaryTreeNode<int> *root) {
    if(root==NULL) {
        return INT_MAX;
    }
    
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int> *root) {
    if(root==NULL) {
        return INT_MIN;
    }
    
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) {
    // Base case
    if(root==NULL) {
        return true;
    }
    
    // Recursive call
    if(maximum(root->left) < root->data && minimum(root->right) >= root->data && isBST(root->left) && isBST(root->right)) {
        return true;
    }    
    return false;
}