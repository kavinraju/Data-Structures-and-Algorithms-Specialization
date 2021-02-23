#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printSubsequences(int arr[], int n)
{
    // Total number of subsequences is 2^n - 1
    int total_count = pow(2, n);

    // Run the counter from 0000..1 to 1111..1
    for (int counter = 1; counter < total_count; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            /*
                check if jth bit is set.
                Eg. counter = 1, j= 0
                counter => 0001
                (1<<j)  => 0001
                    &   => 0001 => 1
                    hence prints a[0] => 1

                counter = 1, j= 1
                counter => 0001
                (1<<j)  => 0010
                    &   => 0000 => 0
                    hence prints nothing and smilarly for j=2, j=3 when counter = 1
                -----------------------------------------------------------------------
                
                counter = 3, j= 0
                counter => 0011
                (1<<j)  => 0001
                    &   => 0001 => 1
                    hence prints a[0] => 1

                counter = 3, j= 1
                counter => 0011
                (1<<j)  => 0010
                    &   => 0010 => 2
                    hence prints a[1] => 2

                counter = 3, j= 2
                counter => 0011
                (1<<j)  => 0100
                    &   => 0000 => 0
                    hence prints nothing and smilarly for j=3, counter = 3 (0011 & 1000 => 0000)
                -----------------------------------------------------------------------

            */
            if (counter & (1 << j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printSubsequences(arr, n);
    return 0;
}
