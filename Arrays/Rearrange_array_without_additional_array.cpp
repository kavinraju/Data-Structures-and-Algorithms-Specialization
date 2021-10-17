#include <iostream>
#include <vector>
using namespace std;

int getPosition(int arr[], int n, int element_to_find)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element_to_find)
        {
            //cout<<"return: "<<arr[i]<<" "<<element_to_find<<" "<<i<<endl;
            return i;
        }
    }
    return -1;
}
int main()
{
    // your code goes here
    int n;
    cin >> n;

    int a[n];
    int order_arr[n]; // {8,4,2,1,7,3,6,5};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> order_arr[i];
    }

    int i = 0;
    bool flag = true;
    int temp, temp2;
    while (i >= 0)
    {

        if (flag)
        {
            int order_i = order_arr[i] - 1;
            temp = a[order_i];
            temp2 = a[i];

            a[i] = temp;
            temp = temp2;
            order_arr[i] = -1;
            int i_srch = getPosition(order_arr, n, i + 1);
            //cout<<"sr "<<i_srch<<endl;
            i = i_srch;
            flag = false;
        }
        else
        {
            temp2 = a[i];
            a[i] = temp;
            temp = temp2;

            int i_srch = getPosition(order_arr, n, i + 1);
            order_arr[i] = -1;
            //cout<<"sr "<<i_srch<<endl;
            int x = -1;
            if (i_srch == -1)
            {

                for (int j = 0; j < n; j++)
                {
                    if (order_arr[j] != -1)
                    {
                        x = j;
                    }
                }
                i = x;
            }
            else
            {
                i = i_srch;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}