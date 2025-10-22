#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    int lon = 0;
    stack<int> par;
    par.push(-1);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            par.push(i);
        }
        else
        {
            par.pop();
            if (par.empty())
            {
                par.push(i);
            }
            else
            {
                int len = i - par.top();
                lon = max(lon, len);
            }
        }
    }

    return lon;
}

int main()
{
    string s = ")()())";
    cout << longestValidParentheses(s);
}