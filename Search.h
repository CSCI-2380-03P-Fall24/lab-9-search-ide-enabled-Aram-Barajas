#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus (+5% to your grade for this lab)! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // ???
void printArray(flexibleType arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
   int temp = 0;
    while(start <= end){
        if(target == arr[temp]){
            return true;
        }
        temp++;
        start++;
    }
    return false;
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
   int left = 0;
   int right = n-1;
    while(left <= right){
    int mid = left+((right-left)/2);
        if(target == arr[mid]){
            return true;
        }
        else if(arr[mid] > target){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return false;	
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
      // base case
    if (n <= 0) {
        return false;
    }
    int mid = n / 2;
    if (charray[mid] == target) {
        return true;
    }
    else if (charray[mid] > target) {
        return binSearchR(target, charray, mid);
    }
    else {
        return binSearchR(target, charray + mid + 1, n - (mid + 1));
    }
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int a, int b) {
     double temp = darray[a];
    darray[a] = darray[b];
    darray[b] = temp;
}

int minFind(double darray[], int size) {
    int smallestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (darray[i] < darray[smallestIndex]) {
            smallestIndex = i;
        }
    }

    return smallestIndex;
}
void newSort(double darray[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i + minFind(darray + i, n - i);
        swap(darray, i, minIndex);
    }
}


// Implement Exponential Search
//    Reuse your iterative binSearch(...) on a narrowed window
//    Assumes the array is sorted in ascending order
// Step 1: Handle edge cases (empty array) and quickly check the first element.
// Step 2: Grow a “bound”: start at 1, then repeatedly double it
//         while you are still inside the array and the current value is less than the target.
// Step 3: Define a search window:
//         - The left edge is halfway back from the current bound.
//         - The right edge is the smaller of (current bound) and (last valid index).
// Step 4: Run your existing binSearch on just that window and return its result.
//         You may pass a pointer to the start of the window and its length,
//         or copy that window to a temporary buffer if you prefer.
bool expSearch(float target, float arr[], int n) {
    if(n == 0){
        return false;
    }
    if(arr[0] == target){
        return true;
    }
    if(arr[0] > target){
        return false;
    }
    int bound = 1;
    while(bound < n && arr[bound] < target){
        bound *=2;
    }
    int left = bound/2;
    int right = 0;
    if(bound < n){
        right = bound;
    }
    else{
        right = n-1;
    }
    int window = right-left+1;
    bool result = false;
    result = binSearch(target, arr+left, window);
    return result;
}
