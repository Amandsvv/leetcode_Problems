#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int toDigit(char ch)
{
    switch (ch)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    }
    return -1;
}
int calPoints(vector<string> &operations)
{
    stack<int> score;

    for (string ch : operations)
    {
        int x = 0;

        if (ch == "+")
        {
            int a = score.top();
            score.pop();
            int b = score.top();
            score.push(a);

            x = b + a;
        }
        else if (ch == "D")
        {
            int a = score.top();
            x = 2 * a;
        }
        else if (ch == "C")
        {
            score.pop();
            continue;
        }
        else
        {
            x = stoi(ch);
        }
        cout<<"x : "<<x<<endl;
        score.push(x);
    }

    int ans = 0;
    while (!score.empty())
    {
        int a = score.top();
        cout<<"Score : "<<a<< " ";
        ans += a;
        cout<<"ans : "<<ans<<endl;
        score.pop();
    }
    return ans;
}
int main()
{
    vector<string> s = {"75","85","C","D","23"};
    cout<<calPoints(s);
}