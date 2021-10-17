#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool flag_reached_nth_round = false;

    for (int i = 1; (i <= n && i >= 1) || i > 0;)
    {
        int ii = 1;
        while (ii <= i)
        {
            cout << ii++;
        }
        int jj = i - 1;
        while (jj > 0)
        {
            cout << jj--;
        }
        cout << endl;

        if (i == n)
        {
            flag_reached_nth_round = true;
        }

        if (flag_reached_nth_round)
        {
            i--;
        }
        else
        {
            i++;
        }
    }
    return 0;
}