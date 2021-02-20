#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
This algorithm run in O(n).
First while loop iterates to the size of arr which is n
Second while loop iterates till size of arr - 1 so n -1
*/
bool checkIfArrayIsSortedAndRotated(vector<int> arr)
{
    //Concatanate the array to res
    vector<int> res;
    res.reserve(arr.size() * 2);
    res.insert(res.end(), arr.begin(), arr.end());
    res.insert(res.end(), arr.begin(), arr.end());

    int start, i = 0;

    //Find the start point to the min element if the element is sorted
    while (i < arr.size())
    {
        if (res[i] > res[i + 1])
        {
            start = i + 1;

            break;
        }
        i++;
    }

    // Check if there is no sign of roation of a sorted array, example {1,2,3}
    if (i == arr.size() - 1)
        return false;

    i = start;
    //Iterate till "arr.size() - 1" ( -1 is coz last element need not be checked if it's < res[i+1])
    //and check if it's sorted
    // If ! (res[i] < res[i+1]) return false

    int j = 0;
    while (j < arr.size() - 1)
    {
        if (!(res[i] < res[i + 1]))
            return false;
        i++;
        j++;
    }
    return true;
}
int main()
{
    vector<int> arr = {1, 2, 3}; //{3, 4, 6, 1, 2, 5}; //{3, 4, 5, 1, 2};
    if (checkIfArrayIsSortedAndRotated(arr))
        cout << endl
             << "Array Is Sorted & Rotated";
    else
        cout << endl
             << "Array Is Not Sorted & Rotated";
    return 0;
}
