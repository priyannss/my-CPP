#include<iostream>
using namespace std;

// It searches for medOfMedian in arr[], and partitions the array 
// around medOfMedian.
int partition(int arr[], int left, int right, int medOfMedian){
    //search for medOfMedian in arr and move it to end
    int i;
    for(i=left; i<right; i++){
        if(arr[i] == medOfMedian)
        break;
    }
    swap(arr[i], arr[right]);

    // standard partition algo
    i = left;
    for(int j=left; j<right; j++){
        if(arr[j] <= medOfMedian){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

// A simple function to find median of arr[].
// only for an array of size 5
int findMedian(int arr[], int size){
    sort(arr, arr+size);  // Sort the array
    return arr[size/2];   // Return middle element
}

int kthSmallest(int arr[], int left, int right, int k){
    if(k > 0 && k <= right-left+1){
        // number of elements in arr
        int n = right-left+1;

        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int median[(n + 4) / 5];
        int i;

        for(i=0; i<n/5; i++){
            median[i] = findMedian(arr+left+i*5, 5);
        }

        //For last group with less than 5 elements
        if (i*5 < n){
            median[i] = findMedian(arr+left+i*5, n%5); 
            i++;
        }

        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need of recursive call
        int medOfMed = (i == 1)? median[i-1] : kthSmallest(median, 0, i-1, i/2);

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, left, right, medOfMed);
  
        // If position is same as k
        if (pos-left == k-1)
            return arr[pos];

        // If position is more, recur for left
        if (pos-left > k-1)
            return kthSmallest(arr, left, pos-1, k);
  
        // Else recur for right subarray
        return kthSmallest(arr, pos+1, right, k-pos+left-1);
    }
  
    // If k is more than number of elements in array
    return INT_MAX;
}

int main(){
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int size = sizeof(arr)/sizeof(int);
    int k = 3;

    int left = 0;
    int right = size-1;

    cout<< "Kth smallest element is : " << kthSmallest(arr, left, right, k) << endl;
    return 0;
}