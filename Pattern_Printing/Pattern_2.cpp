#include <iostream>
using namespace std;

/**
 Input:
 4
 Output:
   0
  101
 21012
3210123
 **/
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // for printing the space
        int space_count = n - 1 - i;
        while (space_count--)
        {
            cout << " ";
        }

        // for priting the number after space till 0
        int ii = i;
        while (ii >= 0)
        {
            cout << ii;
            ii--;
        }

        // for pringint the number after 0
        int j = i;
        ii = 1;
        while (j > 0)
        {
            cout << ii++;
            j--;
        }
        cout << endl;
    }
    return 0;
}