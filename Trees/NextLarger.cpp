/*
    Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.

    Note: Return NULL if no node is present with the value greater than n.

    Input format :
    The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
    The following line contains an integer, that denotes the value of n.

    Output format :
    The first and only line of output contains data of the node, whose data is just greater than n.

    Constraints:
    Time Limit: 1 sec

    Sample Input 1 :
    10 3 20 30 40 2 40 50 0 0 0 0 
    18
    Sample Output 1 :
    20

    Sample Input 2 :
    10 3 20 30 40 2 40 50 0 0 0 0 
    21
    Sample Output 2:
    30
*/

/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Base case
    if(root==NULL) {
        return root;
    }
    
    TreeNode<int>* nextLarger = NULL;
    
    // Recursive call
    for(int i=0; i<root->children.size(); i++) {
        TreeNode<int>* temp = getNextLargerElement(root->children[i], x);
        
        if(temp!=NULL && temp->data > x && nextLarger==NULL) {
            nextLarger = temp;
        }
        if(temp!=NULL && temp->data > x && nextLarger!=NULL){
            if(temp->data > nextLarger->data) {
                nextLarger = temp;
            }
        }
    }
    
    if(root->data > x && nextLarger!=NULL && root->data < nextLarger->data) {
        return root;
    }
    if(root->data > x && nextLarger==NULL) {
        return root;
    }
    
    return nextLarger;
}