#include<iostream>
using namespace std;

int squareRoot(int n){
    int left = 0;
    int right = n;

    int ans = 0;
    while(left <= right){
        long long int mid = (left+right)/2;
        long long int square = mid*mid;

        if(square == n)
        return mid;

        else if(square < n){
            ans = mid;
            left = mid+1;
        }
        else
        right = mid-1;
    }

    return ans;
}

double morePrecision(int num , int precision , int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i=0 ; i<precision ; i++){
        factor /= 10;

        for(double j=ans ; j*j<num ; j+=factor){
            ans = j;
        }
    }

    return ans;
}

int main(){
    int n;
    cout<< "Enter a number : ";
    cin>> n;

    int tempSol = squareRoot(n);
    cout<< "Square root of n : " << morePrecision(n , 3 , tempSol) << endl;
    return 0;
}