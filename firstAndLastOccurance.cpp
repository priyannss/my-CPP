#include<iostream>
using namespace std;

void searchOccurance(int arr[] , int size , int key){
    int left = 0;
    int right = size-1;
    int i = -1;
    int j = -1;
    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] == key){
            i = mid;
            j = mid;
            break;
        }
        else if(key < arr[mid])
        right = mid-1;
        else left = mid+1;
    }

    if(i == -1 && j == -1){
        cout<< key << " is not present in array"<< endl;
        return;
    }

    while(arr[i] == key)
    i--;
    while(arr[j] == key)
    j++;

    cout<< "Starting index of " << key << " is : " << i+1 << endl;
    cout<< "Ending index of " << key << " is : " << j-1 << endl;
}

int main(){
    int arr[] = {1, 2 , 4 , 4 , 4 , 4 , 5, 7 , 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<< "Enter a key : ";
    cin>> k;

    searchOccurance(arr , size , k);

    return 0;
}