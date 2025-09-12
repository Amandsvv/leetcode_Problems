#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberS(char ch)
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
    default : return -1;

    }
}

int myAtoi(string s)
{
    int pos = 1;
    int num = 0;
    int n = s.size();
    int i = 0;

    while ( i< n && s[i] == ' ') i++; // skips unti space comes

    //Handling sign
    if(i<n && (s[i] == '+' || s[i] == '-')){
        pos = (s[i] == '-') ? -1:1;
        i++;
    }

    //digit conversion
    for(;i<n; i++){
        int digit = numberS(s[i]);
        if(digit == -1) break; //stops if not a digit

        //check overflow
        if(num > (INT32_MAX - digit) /10){
            return pos == 1 ?INT16_MAX:INT16_MIN;
        }

        num = num*10 + digit;

    }
    return pos*num;
}

int main()
{
    string s = "   -042";
    cout << myAtoi(s);
    cout<<INT16_MAX;
}