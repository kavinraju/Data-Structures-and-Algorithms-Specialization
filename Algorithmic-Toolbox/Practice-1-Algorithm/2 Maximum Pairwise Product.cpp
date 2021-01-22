// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    
    sort(a.begin(), a.end());
    
    long long result = (long long) a.at(n-1) * a.at(n-2);
    cout<<result;

    return 0;
}