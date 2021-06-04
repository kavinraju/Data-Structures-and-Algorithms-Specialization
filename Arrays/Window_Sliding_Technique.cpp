#include <iostream>
using namespace std;

/*
https://www.geeksforgeeks.org/window-sliding-technique/
Given an array of integers of size ‘n’.
Our aim is to calculate the maximum sum of ‘k’ 
consecutive elements in the array.

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

*/

int maxSum(int arr[], int n, int k){
    
    if(n < k){
        cout<<"Invalid";
        return -1;
    }

    int max_sum = 0;

    for(int i=0;i<k;i++)
        max_sum += arr[i];
    
     int window_sum = max_sum;
    for(int i=k; i<n; i++){
       window_sum += arr[i] - arr[i-k];
       if(window_sum > max_sum)
            max_sum = window_sum;
    }

    return max_sum;
}

int main(){
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSum(arr, n, k);
    return 0;
}