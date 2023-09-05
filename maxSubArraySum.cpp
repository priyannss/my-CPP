#include<iostream>
#include<limits>
using namespace std;

int maxSubArraySum(vector<int> arr){
    int maxSoFar = INT_MIN;
    int maxTillHere = 0;
    for(int i=0; i<arr.size(); i++){
        maxTillHere = maxTillHere + arr[i];
        maxSoFar = (maxTillHere > maxSoFar) ? maxTillHere : maxSoFar;

        if(maxTillHere < 0)
        maxTillHere = 0;
    }

    return maxSoFar;
}

int main(){
    vector<int> arr;
    arr.push_back(-2);
    arr.push_back(-3);
    arr.push_back(4);
    arr.push_back(-1);
    arr.push_back(-2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(-3);

    cout<< "Maximum SubArray sum is : " << maxSubArraySum(arr) << endl;
}