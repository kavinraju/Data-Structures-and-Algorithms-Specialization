#include <iostream>
using namespace std;

/*
I/p:
    3
    1 2 3
    4 5 6
    7 8 9
    2
O/p:
    12 16 24 28 

I/P:
    5
    1 1 1 1 1
    2 2 2 2 2
    3 3 3 3 3
    4 4 4 4 4
    5 5 5 5 5
    3
O/P:
    18 18 18 27 27 27 36 36 36 
*/

int main()
{
    // your code goes here
    int n;
    cin >> n;

    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < n; i++)
    { //row

        for (int j = 0; j < n; j++)
        { //col

            //cout<<"(i,j): "<<i<<","<<j<<endl;

            int sum = 0;
            if (j + k - 1 < n && i < k && n != k)
            { // condition for coll && condition for row && condition for n != k
                //cout<<"j+k = "<<j+k<<endl;
                int ii = i, jj = j, p = 0, q = 0;
                while (p < k && ii < n)
                {
                    jj = j;
                    q = 0;
                    //cout<<"(p,q): "<<p<<","<<q<<endl;
                    while (q < k && jj < n)
                    {
                        //cout<<"(ii,jj): "<<ii<<","<<jj<<endl;
                        sum += arr[ii][jj];
                        //cout<<"sum += arr[ii][jj] = "<<sum<<endl;
                        jj++;
                        q++;
                    }
                    ii++;
                    p++;
                }
                //cout<<"SUM = "<<sum<<endl<<endl;
                cout << sum << " ";
            }
            else if (n == k)
            {
                while (i < n)
                {
                    j = 0;
                    while (j < n)
                    {
                        sum += arr[i][j];
                        j++;
                    }
                    i++;
                }
                cout << sum;
            }
        }
    }

    return 0;
}
