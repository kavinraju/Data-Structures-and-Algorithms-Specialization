#include <iostream>
#include <vector>

using namespace std;

void printSubarrays(vector<int> arr, int start, int end)
{
    if (end == arr.size())
        return;

    else if (start > end)
    {
        cout << "#\n";
        printSubarrays(arr, 0, end + 1);
    }
    else
    {
        cout << "[";
        for (int i = start; i < end; i++)
        {
            cout << arr[i] << ",";
        }

        cout << arr[end] << "]" << endl;
        cout << "%\n";
        printSubarrays(arr, start + 1, end);
        }

    return;
}

int main()
{
    vector<int> arr;
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    printSubarrays(arr, 0, 0);
    return 0;
}