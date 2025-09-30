#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int c2n(char ch)
{
    switch (ch)
    {
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case '0':
        return 0;
    }
    return -1;
}
string addStrings(string num1, string num2)
{
    int n1 = num1.size() - 1;
    int n2 = num2.size() - 1;
    string ans = "";
    int carry = 0;
    int sum = 0;

    while (n1 >= 0 && n2 >= 0)
    {
        int sum = carry + c2n(num1[n1]) + c2n(num2[n2]);
        ans += to_string(sum % 10);
        carry = sum / 10;
        n1--;
        n2--;
        cout<<"ans is : "<<ans<<endl;
    }

    cout<<"ans a last : "<<ans<<" n1 : "<<n1<<" n2 : "<<n2<<endl;
    while (n1 >= 0)
    {
        int sum = carry + c2n(num1[n1]);
        ans += to_string(sum % 10);
        carry = sum / 10;
        n1--;
    }
    while (n2 >= 0)
    {
        int sum = carry + c2n(num2[n2]);
        ans += to_string(sum % 10);
        carry = sum / 10;
        n2--;
    }
    cout<<"ans lastam : "<<ans<<endl;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // string s = "aaaaaaa";
    // vector<string> wordDict = {"aaaa", "aaa"};

    // cout<<wordBreak(s,wordDict)<<endl;

    string n1 = "11";
    string n2 = "123";

    cout << "Sum is : " << addStrings(n1,n2);
}