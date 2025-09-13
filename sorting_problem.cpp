#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countWord(string s)
{
    int word = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            word++;
        }
    }
    return word + 1;
}

int lastPos(int i, string s)
{
    while (s[i] != ' ' && i < s.size())
    {
        i++;
    }
    return i;
}

int pos(char ch)
{
    switch (ch)
    {
    case '0':
        return 0;
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
    }
}

string sortSentence(string s)
{
    int word = countWord(s);
    vector<string> my_str(word, "");

    for (int i = 0; i < s.size(); i++)
    {
        int j = lastPos(i, s);
        int position = pos(s[j - 1]);

        string subString = s.substr(i, j - 1 - i);
        my_str[position - 1] = subString;
        i = j;
    }
    s.erase();

    for (int i = 0; i < my_str.size(); i++)
    {
        s.append(my_str[i]);
        s.push_back(' ');
    }
    s.pop_back();
    return s;
}

int main()
{

    vector<string> my_str;
    string s = "is2 my3 This1 sentence4";

    cout << s << endl;
    s = sortSentence(s);
    cout << s << endl;

    return 0;
}