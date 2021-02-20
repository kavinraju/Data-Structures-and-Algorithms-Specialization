#include <iostream>
#include <vector>
using namespace std;

/**
 * Time complexity : O(n) 
 * Auxiliary Space : O(n)
 */
void arrayRotationMethod1(int arr[], int d)
{
    cout << "arrayRotationMethod1:\n";
    int n = sizeof(arr) - 1; /// sizeof(arr)  return size of arr + 1
    //cout << "n = " << n << endl;
    int rev[n];
    for (int i = 0; i < n; i++)
    {
        if (i + d < n)
            rev[i] = arr[i + d];
        else
        {
            int x = abs(n - i - d);
            rev[i] = arr[x];
        }
        cout << rev[i] << ",";
    }
}

/**
 * Time complexity : O(n) 
 * Auxiliary Space : O(d)
 */
void arrayRotationMethod2(int arr[], int d)
{
    cout << "arrayRotationMethod2:\n";
    int n = sizeof(arr) - 1; /// sizeof(arr)  return size of arr + 1
    // Create a temp for storing first d elements
    int temp[d];
    int i = 0;

    // Store the first d elements in temp
    while (i < d)
    {
        temp[i] = arr[i];
        i++;
    }

    // Shift the elements after d from 0th position in arr
    i = 0;
    int j = d;
    while (j < n)
        arr[i++] = arr[j++];

    // Append the temp elements to the arr
    j = 0;
    while (j < d)
        arr[i++] = temp[j++];
}

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    arr[n - 1] = temp;
}
/**
 * Time complexity : O(n) 
 * Auxiliary Space : O(1)
 */
void arrayRotationMethod3(int arr[], int d)
{
    cout << "arrayRotationMethod3:\n";
    int n = sizeof(arr) - 1; /// sizeof(arr)  return size of arr + 1
    for (int i = 0; i < d; i++)
        leftRotateByOne(arr, n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    arrayRotationMethod3(arr, d);

    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ",";
    return 0;
}
