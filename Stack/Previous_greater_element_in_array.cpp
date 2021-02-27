#include <iostream>
#include <stack>

using namespace std;

void printPreviousGreaterElements(int arr[], int n)
{
    stack<int> s;

    // First element has no previous greater element, hence print -1
    //and push the first element into stack
    cout << "-1, ";
    s.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        // If top element is greater than ith element, print top and push the ith element into stack
        if (s.top() > arr[i])
        {
            cout << s.top() << ", ";
            s.push(arr[i]);
        }
        else
        {
            // else pop out the elements from stack which are less than arr[i]
            while (!s.empty() && s.top() < arr[i])
                s.pop();

            // If stack becomes empty no greater elements there previously, hence print -1 and
            // push the arr[i] to stack
            if (s.empty())
            {
                cout << "-1, ";
                s.push(arr[i]);
            }
            else
            {
                cout << s.top() << ", ";
            }
        }
    }
}

int main()
{
    int arr[] = {10, 4, 2, 20, 40, 12, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printPreviousGreaterElements(arr, n);
    return 0;
}
