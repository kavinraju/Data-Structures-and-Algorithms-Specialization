#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{

    int h1_sum, h2_sum, h3_sum;
    h1_sum = accumulate(h1.begin(), h1.end(), 0);
    h2_sum = accumulate(h2.begin(), h2.end(), 0);
    h3_sum = accumulate(h3.begin(), h3.end(), 0);

    if ((h1_sum == h2_sum && h2_sum == h3_sum) || (h1_sum == 0 && h2_sum == 0 && h3_sum == 0))
        return h1_sum;

    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());

    bool equal_heights = false;

    while (!equal_heights)
    {
        if (h1_sum >= h2_sum && h1_sum >= h3_sum)
        {
            //cout<<h1.back();
            h1_sum -= h1.back();
            h1.pop_back();
        }
        else if (h2_sum >= h1_sum && h2_sum >= h3_sum)
        {
            h2_sum -= h2.back();
            //cout<<h2.back();
            h2.pop_back();
        }
        else if (h3_sum >= h2_sum && h3_sum >= h1_sum)
        {
            h3_sum -= h3.back();
            //cout<<h3.back();
            h3.pop_back();
        }

        if ((h1_sum == h2_sum && h2_sum == h3_sum) || (h1_sum == 0 && h2_sum == 0 && h3_sum == 0))
            equal_heights = true;
    }
    return h1_sum;
}

int main()
{
    //Implement the input process and call the equalStacks() function
    return 0;
}
