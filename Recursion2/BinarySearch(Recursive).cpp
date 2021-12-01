/*
    Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
    Return -1 if x is not present in the given array.
    Note : If given array size is even, take first mid.

    Input format :
    Line 1 : Array size
    Line 2 : Array elements (separated by space)
    Line 3 : x (element to be searched)

    Sample Input :
    6
    2 3 4 5 6 8 
    5 
    Sample Output:
    3 
*/

int binarySearchHelper(int input[], int startIndex, int endIndex, int element) {
    // Base case
    if(startIndex >= endIndex) {
        if(input[startIndex] == element) {
            return startIndex;
        }
        return -1;
    }
    
    int mid = (startIndex+endIndex)/2;
    if(input[mid] == element) {
        return mid;
    }
    // Recursive call
    else if(input[mid] < element) {
        return binarySearchHelper(input, mid+1, endIndex, element);
    }
    // Recursive call
    else if(input[mid] > element) {
        return binarySearchHelper(input, startIndex, mid-1, element);
    }
}

int binarySearch(int input[], int size, int element) {
    return binarySearchHelper(input, 0, size-1, element);
}