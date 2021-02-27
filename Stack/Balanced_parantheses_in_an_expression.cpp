#include <iostream>
#include <stack>

using namespace std;

bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char x;

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr.at(i) == '[' || expr.at(i) == '{' || expr.at(i) == '(')
        {
            s.push(expr[i]);
            continue;
        }

        if (s.empty())
            return false;

        switch (expr.at(i))
        {
        case ')':
            x = s.top();
            s.pop();
            if (x != '(')
                return false;
            break;

        case '}':
            x = s.top();
            s.pop();
            if (x != '{')
                return false;
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x != '[')
                return false;
            break;
        }
    }

    return s.empty();
}

int main()
{
    string expr = "{{()}[]";

    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
