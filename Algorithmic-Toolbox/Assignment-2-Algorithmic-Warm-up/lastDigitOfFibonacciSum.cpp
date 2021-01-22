// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<string.h>
#include<bits/stdc++.h>
#include <sstream>
using namespace std;

/*
	We need to find the remainder when N is divided by the Pisano Period of M. Then calculate F(N)remainder mod M for the newly calculated N.
	So to compute, say F2019 mod 5, we’ll find the remainder of 2019 when divided by 20 (Pisano Period of 5 is 20). 2019 mod 20 is 19.
	 Therefore, F2019 mod 5 = F19 mod 5 = 1. This property is true in general. 
*/

int fibonacciSumLastDigit(long long n){
    
   	// The first two Fibonacci numbers 
	long long f0 = 0; 
	long long f1 = 1; 
	
		// Base case 
	if (n == 0) 
		return 0; 
	if (n == 1) 
		return 1; 
	else
	{ 
		// Pisano period for % 10 is 60 
		long long rem = n % 60;
		
		// Checking the remainder 
		if(rem == 0) 
			return 0; 
			
		// The loop will range from 2 to two terms after the remainder 
		for(long long i = 2; i < rem + 3; i++) 
		{ 
		long long f = (f0 + f1) % 60;
		f0 = f1; 
		f1 = f; 
		} 
		
		//cout<<"f1: "<<f1<<endl;
		long long s = f1 - 1; 
		return s; 
	}
}

int main() {
    // Write C++ code here
    long long n;
    cin>>n;
    int fibSum = 0;
    fibSum = fibonacciSumLastDigit(n);
   // cout<<fib<<endl;
    
    stringstream my_stream;
    string str_fibSum;
    my_stream << fibSum;
    str_fibSum = my_stream.str();
    cout<<str_fibSum[str_fibSum.length() - 1];

    return 0;
}
