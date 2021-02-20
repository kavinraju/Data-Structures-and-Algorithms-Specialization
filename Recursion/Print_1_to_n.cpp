#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print1toN(int n)
{
    if (n > 1)
        print1toN(n - 1);
    cout << n << " ";
}

void printNto1(int n)
{
	cout << n << " ";
    if (n > 1)
        printNto1(n - 1);
    
}

int main()
{
    print1toN(10);
    cout<<endl;
    printNto1(10);
    return 0;
}
