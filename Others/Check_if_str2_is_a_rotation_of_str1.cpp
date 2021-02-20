#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

bool isRotated(string s1, string s2)
{

    if (s1.size() != s2.size())
        return false;

    int n = s1.size() + 1;

    string s3 = s1 + s1;

    char c_s3[2 * n], c_s1[n];
    strcpy(c_s3, s3.c_str());
    strcpy(c_s1, s1.c_str());
    char *substr = strstr(c_s3, c_s1);

    if (substr)
        return true;
    else
        return false;
}

int main()
{

    string s1, s2;

    cout << "Enter string 1: " << endl;
    getline(cin, s1);
    cout << "Enter string 2: " << endl;
    getline(cin, s2);

    if (isRotated(s1, s2))
        cout << s2 << " is a rotated string of " << s1 << endl;
    else
        cout << s2 << " is not a rotated string of " << s1 << endl;
    return 0;
}
