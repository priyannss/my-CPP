#include<iostream>
using namespace std;

int getPivot(int arr[] , int size){
    int left = 0;
    int right = size-1;
    int mid = (left+right)/2;

    while(left < right){
        if(arr[mid] >= arr[0])
        left = mid+1;
        else
        right = mid;

        mid = (left+right)/2;
    }

    return left;
}

int main(){
    int arr[] = {9, 1, 2, 3, 4, 6, 7};
    int size = sizeof(arr)/sizeof(int);

    int pivotIdx = getPivot(arr , size);
    cout<< "Pivot is present at index : " << pivotIdx << endl;
    return 0;
}