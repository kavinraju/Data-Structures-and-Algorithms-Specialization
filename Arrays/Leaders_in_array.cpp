#include <iostream>

using namespace std;

/**
Time Complexity: O(n) 
Auxiliary Space: O(1) 
*/
void leaderInArray(int arr[], int n)
{

    int leader = arr[n - 1];
    cout << "Leader elements: " << leader << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (leader < arr[i])
        {
            leader = arr[i];
            cout << leader << " ";
        }
    }
}
int main()
{
    int arr[] = {18, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    leaderInArray(arr, n);
    return 0;
}
