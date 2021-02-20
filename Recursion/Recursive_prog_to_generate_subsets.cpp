#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/

void printSubsets(string str, int index = -1, string current = "")
{
    int n = str.length();
    if (index == n)
        return;

    cout << current << endl; // Print the current string, which is a subset

    for (int i = index + 1; i < n; i++)
    {
        current += str[i];
        //cout<<"i = "<<i<<" current = "<<current<<endl;

        printSubsets(str, i, current);
        current.erase(current.length() - 1);
    }
    return;
}

int main()
{
    string str = "bcja";
    printSubsets(str);
    return 0;
}
