/*#include <bits/stdc++.h> 
using namespace std; 
//long long* dp;
int dp[4545];

int fib(int n) 
{ 
	if (n <= 1) 
		return n; 

	// temporary variables to store 
	// values of fib(n-1) & fib(n-2) 
	int first, second; 

	if (dp[n - 1] != -1) 
		first = dp[n - 1]; 
	else
		first = fib(n - 1); 

	if (dp[n - 2] != -1) 
		second = dp[n - 2]; 
	else
		second = fib(n - 2); 

	// memoization 
	return dp[n] = first + second; 
} 

int main() 
	{ 
		long long n;
		cin>>n;
		
		//long long dp_[n];
		//dp = dp_;
		memset(dp, -1, sizeof(dp)); 
	
		cout << fib(n); 
		getchar(); 
		return 0; 
	
		// This code is contributed by Bhavneet Singh 
	}
*/

// Online C++ compiler to run C++ program online

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/*
long long fibonacciNumber(long long n){
    
    if(n <= 1)
        return n;
        
    vector<long long> a;
    a.push_back(0);
    a.push_back(1);
    for(long i=2;i<=n;i++){
        a.push_back(a.at(i-1) + a.at(i-2));
        cout<<"at i = "<<i<<" -> "<<a.at(i)<<endl;
    }
    //cout<<endl<<a.at(n-1);
    
    return a.at(n);
}*/

long long fibonacciNumber(long long n){
    
    if(n <= 1)
        return n;
        
    long long a,b, c;
    a = 0;
    b = 1;    
    for(long i=1;i<=n;i++){
       c = a+b;
       b = a;
       a = c;
       
    //cout<<"at i = "<<i<<" -> "<<c<<endl;
    
    }
	    
    return c;
}


int main() {
    // Write C++ code here
    long long n;
    cin>>n;
    cout<<endl<<fibonacciNumber(n)<<endl;

    return 0;
}
