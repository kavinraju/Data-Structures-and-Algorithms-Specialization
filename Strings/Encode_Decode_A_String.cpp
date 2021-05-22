#include <iostream>
#include <string>
using namespace std;

/*
Eg 1: Input: a1b10
       Output: abbbbbbbbbb
Eg: 2: Input: b3c6d15
          Output: bbbccccccddddddddddddddd
The number varies from 1 to 99.
*/

int main()
{
    // your code goes here
    string s;
    getline(cin, s);
    cout << "Decoding " << s << endl;
    int count = 0;
    char ch;
    string decodedStr;

    //s = "h1n1w1n1k1u1e1w1h1s1q1m1g1b2u1q1c1l1j2i1v1s1w1m1d1k1q1t1b1x1i1x1m1v1t1r2b1l1j1p1t1n1s1n1f1w1z1q1f1j1m1a1f1a1d1r2w1s1o1f1s1b1c1n1u1v1q1h1f2b1s1a1q1x1w1p1q1c1a1c1";

    // Decoding the String s - Eg: b3a1c3 to bbbaccc
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {
            count = count * 10 + (s[i] - '0');
        }
        else if (s[i] > '9')
        {
            ch = s[i];
        }

        if (count > 0 && i < s.length() - 1 && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
        {
            while (count--)
            {
                cout << ch;
                decodedStr += ch;
            }
            count = 0;
        }
        else if (i == s.length() - 1)
        {
            while (count--)
            {
                cout << ch;
                decodedStr += ch;
            }
        }
    }

    cout << "decodedStr: " << decodedStr << endl;

    string encodedStr;
    s = decodedStr;

    // Encoding - Example:  bbbaccc to b3a1c3
    for (int i = 0; i < s.length(); i++)
    {
        int j = 1;
        while (i < s.length() - 1 && s[i] == s[i + 1])
            j++, i++;

        encodedStr += s[i] + to_string(j);
    }

    cout << "Encoded again to " << encodedStr;
    return 0;
}
