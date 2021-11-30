/*
    Sort an array A using Quick Sort.
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
    1 5 2 7 3
    Sample Output 2 :
    1 2 3 5 7 
*/

int partition(int input[], int startIndex, int endIndex) {   
    // Select a pivot element
    int pivot = input[startIndex];
    
    // Count the number of elements smaller than the pivot
    int count = 0;
    for(int i=startIndex+1; i<=endIndex; i++) {
        if(input[i] <= pivot) {
            count++;
        }
    }
    
    // Place the pivot on its correct place
    int pivotIndex = startIndex + count;
    input[startIndex] = input[pivotIndex];
    input[pivotIndex] = pivot;
    
    // Placing all smaller elements on the left and
    // greater elements on the right of the pivot,
    // but they need not be sorted
    int i=startIndex;
    int j=endIndex;
    while(i < pivotIndex && j > pivotIndex) {
        if(input[i] <= pivot) {
            i++;
        }
        else if(input[j] > pivot) {
            j--;
        }
        else {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSortHelper(int input[], int startIndex, int endIndex) {
    // Base case
    if(startIndex >= endIndex) {
        return;
    }

    // Partitioning the array
    int x = partition(input, startIndex, endIndex);
    
    // Recursive call
    quickSortHelper(input, startIndex, x-1);
    quickSortHelper(input, x+1, endIndex);
}

void quickSort(int input[], int size) {
    quickSortHelper(input, 0, size-1);
}