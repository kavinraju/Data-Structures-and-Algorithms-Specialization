// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<string.h>
#include<bits/stdc++.h>
#include <sstream>
using namespace std;

long  fibonacciLastDigit(long long n){
    
    if(n <= 1)
        return n;
    long a, b, c;
    a = 0;
    b = 1;
    for(int i=2;i<=n;i++){
       c = (a % 10 + b % 10) % 10;
       a = b;
       b = c;
      // cout<<c<< " ";
    }
    return c;
}

int main() {
    // Write C++ code here
    long long n;
    cin>>n;
    long long fib = 0;
    fib = fibonacciLastDigit(n);
   // cout<<fib<<endl;
    
    stringstream my_stream;
    string str_fib;
    my_stream << fib;
    str_fib = my_stream.str();
    cout<<endl<<str_fib[str_fib.length() - 1];

    return 0;
}
