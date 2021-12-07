/*
    For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.

    Note :
    No need to print the list, it has already been taken care. Only return the new head to the list.
    
    Input format:
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
    The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

    Remember/Consider :
    While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
    
    Output format:
    For each test case/query, print the elements of the updated singly linked list.
    Output for every test case will be printed in a seperate line.

    Constraints :
    1 <= t <= 10^2
    0 <= M <= 10^5
    Where M is the size of the singly linked list.
    Time Limit: 1sec

    Sample Input 1 :
    1
    1 4 5 2 -1
    Sample Output 1 :
    1 5 4 2 
    
    Sample Input 2 :
    2
    1 11 3 6 8 0 9 -1
    10 20 30 40 -1
    Sample Output 2 :
    1 11 3 9 6 8 0
    10 20 30 40
*/

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *evenAfterOdd(Node *head) {
    // Divide original LL into two - odd and even
    // 4 pointers to maintain head and tail of both LL
    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    
    while(head!=NULL) {
        if(head->data % 2 == 1) {
            // Check if the odd LL is empty
            if(oddHead == NULL) {
                oddHead = head;
                oddTail = head;
            }
            else {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        else {
            // Check if the even LL is empty
            if(evenHead == NULL) {
                evenHead = head;
                evenTail = head;
            }
            else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        head = head->next;
    }
    
    // Separate both LL from the original
    if(oddTail!=NULL) {
        oddTail->next = NULL;
    }
    if(evenTail!=NULL) {
        evenTail->next = NULL;
    }
    
    // Combine both LL
    if(oddTail==NULL) {
        return evenHead;
    }
    oddTail->next = evenHead;
    return oddHead;
}