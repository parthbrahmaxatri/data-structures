/*
    Sort an array A using Merge Sort.
    Change in the input array itself. So no need to return or print anything.

    Input format :
    Line 1 : Integer n i.e. Array size
    Line 2 : Array elements (separated by space)

    Output format :
    Array elements in increasing order (separated by space)

    Constraints :
    1 <= n <= 10^3

    Sample Input 1 :
    6 
    2 6 8 5 4 3
    Sample Output 1 :
    2 3 4 5 6 8
    
    Sample Input 2 :
    5
    2 1 5 2 3
    Sample Output 2 :
    1 2 2 3 5 
*/

void mergeTwoSortedArrays(int input[], int startIndex, int endIndex) {
    int size = (endIndex-startIndex) + 1;
    int mid = (startIndex+endIndex)/2;
    
    // Creating an extra array to sort the two given arrays
    int *output = new int[size];
    
    int i = startIndex;
    int j = mid+1;
    int k = 0;
    
    // Comparing the starting elements of both arrays and
    // then copying the smaller one into the output array
    while(i<=mid && j<=endIndex) {
        if(input[i] < input[j]) {
            output[k] = input[i];
            i++;
            k++;
        } else {
            output[k] = input[j];
            j++;
            k++;
        }
    }
    
    while(i<=mid) {
        output[k] = input[i];
        i++;
        k++;
    }
    while(j<=endIndex) {
        output[k] = input[j];
        j++;
        k++;
    }
    
    // Copying the output array back into the input array
    int m=0;
    for(int i=startIndex; i<=endIndex; i++) {
        input[i] = output[m];
        m++;
    }
    
    delete [] output;
}

void mergeSortHelper(int input[], int startIndex, int endIndex) {
    // Base case
    if(startIndex >= endIndex) {
        return;
    }
    
    int mid = (startIndex+endIndex)/2;
    
    // Recursive call: Splitting the array into two halves
    mergeSortHelper(input, startIndex, mid);
    mergeSortHelper(input, mid+1, endIndex);
    
    // Merging the two sorted arrays
    mergeTwoSortedArrays(input, startIndex, endIndex);
}

void mergeSort(int input[], int size){
    mergeSortHelper(input, 0, size-1);
}