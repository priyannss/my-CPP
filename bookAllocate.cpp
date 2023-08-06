#include<iostream>
using namespace std;

bool isPossible(int arr[] , int size , int students , int mid){
    int stuCount = 1;
    int pageSum = 0;

    for(int i=0 ; i<size ; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            stuCount++;

            if(stuCount > students || arr[i] > mid)
            return false;

            pageSum = arr[i];
        }
    }

    return true;
}

int allocateBooks(int arr[] , int size , int students){
    int sum = 0;
    for(int i=0 ; i<size ; i++){
        sum += arr[i];
    }

    int left = 0;
    int right = sum;
    int ans = -1;

    while(left <= right){
        int mid = (left+right)/2;

        if(isPossible(arr , size , students , mid)){
            ans = mid;
            right = mid-1;
        }
        else left = mid+1;
    }

    return ans;
}

int main(){
    int arr[] = {10 , 20 , 30 , 40};
    int size = sizeof(arr)/sizeof(int);

    int students = 2;
    int minPageAssigned = allocateBooks(arr , size , students);

    cout<< "Minimum page assigned is : " << minPageAssigned << endl;

    return 0;
}