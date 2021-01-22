// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    
    int gcd = 0;
    // Swap the variales if b > a
    if(b > a){
    	int temp = a;
    	a = b;
    	b = temp;
	}
	
    while(a > b){
        int a_ = a % b;
        //cout<<" a_ "<<a_<<endl;
        if(a_ == 0)
            return b;
        a = b;
        b = a_;
    }
}

int main() {
    // Write C++ code here
    int a,b;
    cin>>a>>b;
    cout<<gcd(a, b);

    return 0;
}
