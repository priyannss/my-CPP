#include<iostream>
using namespace std;

int getPivot(int arr[] , int size){
    int left = 0;
    int right = size-1;

    while(left < right){
        int mid = (left+right)/2;

        if(arr[mid] >= arr[0])
        left = mid+1;
        else
        right = mid;
    }

    return left;
}

int binarySearch(int arr[] , int left , int right , int element){

    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] == element)
        return mid;
        else if(element < arr[mid])
        right = mid-1;
        else left = mid+1;
    }

    return -1;
}

int main(){
    int arr[] = {9, 1, 2, 3, 4, 6, 7};
    int size = sizeof(arr)/sizeof(int);

    int key;
    cout<< "Enter the key to be searched : ";
    cin>> key;

    int pivotIdx = getPivot(arr , size);

    if(key >= arr[pivotIdx] && key <= arr[size-1]){
        int idx = binarySearch(arr , pivotIdx , size-1 , key);
        cout<< "Element is present at index : " <<idx <<endl;
    }
    else{
        int idx = binarySearch(arr , 0 , pivotIdx-1 , key);
        cout<< "Element is present at index : " <<idx <<endl;
    }

    return 0;
}