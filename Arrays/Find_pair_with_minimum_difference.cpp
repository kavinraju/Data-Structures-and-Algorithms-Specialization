#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // int min; // Assigned 62355532 instead of INT_MAX
    pair<int, int> p = pair<int, int>();

    // O(n^2)
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int diff = abs(a[i] - a[j]);

            if (i == 0 && j == 0)
                min = diff;

            if (i != j && diff < min)
            {
                min = diff;
                p.first = a[i];
                p.second = a[j];
            }
        }
    }
    cout << "The pair minimum diff (" << min << ") is " << p.first << "," << p.second;
    */

    /* Lesson - DO NOT assume sum = 0 or sum = MIN_INT, this wont't lead to correct output always since,
    if sum = 0 then for the sum with negative values 0 will always be the max.*/
    int min_diff;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0, k = n - 1; j <= n / 2; j++, k--)
        {

            if (i != j && i != k)
            {
                // cout << "1) \n";
                int diff_1 = abs(a[i] - a[j]);
                int diff_2 = abs(a[i] - a[k]);
                int diff = (diff_1 < diff_2) ? diff_1 : diff_2;

                if (diff < min_diff)
                { // Check if diff is less than the min_diff
                    min_diff = diff;

                    // if condition to store the respective pair for which the diff was minimum
                    if (diff == diff_1)
                    {
                        // cout << "min_diff 1 = " << min_diff << endl;
                        p.first = a[i];
                        p.second = a[j];
                    }
                    else
                    {
                        // cout << "min_diff 2 = " << min_diff << endl;
                        p.first = a[i];
                        p.second = a[k];
                    }
                }
            }
            else if (i != k && i == j)
            { // Here is where we assign the first diff value
                // cout << "3) \n";
                int diff = abs(a[i] - a[k]);
                if (i == 0 && j == 0)
                { // this condition is to get started with the 1st loop
                    min_diff = diff;
                    // cout << "min_diff = " << min_diff << endl;
                    p.first = a[i];
                    p.second = a[k];
                }
            }
        }
    }

    cout << "The pair minimum diff is " << p.first << "," << p.second;
    return 0;
}