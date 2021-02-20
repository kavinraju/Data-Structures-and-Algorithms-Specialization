#include <iostream>
#include <vector>

using namespace std;

/*
	I/P: 1,0,1,1,0,0,1
	O/P: 0,0,0,1,1,1,1
*/
int main()
{
	
    vector<int> arr =  {1, 0, 1, 1, 0, 0, 1};
    int i = 0, n = arr.size();
	int j = n;
    int k = 0;
    vector<int> a = vector<int>(n, 0);
    while (k < n)
    {
        if (arr.at(k) == 0)
        {
            a[i++] = 0;
        }
        else if (arr[k] == 1)
        {
            a[j--] = 1;
        }
        k++;
    }

    k = 0;

    while (k < n)
    {
        cout << a[k] << " ";
        k++;
    }

    return 0;
}
