#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int toInt(char ch){
        switch (ch){
            case '1': return 1; break;
            case '2': return 2; break;
            case '3': return 3; break;
            case '4': return 4; break;
            case '5': return 5; break;
            case '6': return 6; break;
            case '7': return 7; break;
            case '8': return 8; break;
            case '9': return 9; break;
            case '0': return 0; break;
        }
        return -1;
    }
    bool hasSameDigits(string s) {
        int j = 1;
        while(s.size() != 2){
            int newS = 0;
            for(int i = 1; i < s.size(); i++){
                int dig = (toInt(s[i-1]) +toInt(s[i])) % 10;
                newS = newS*10+dig;
            }
            cout<<"New String : "<<newS<<endl;
            s = to_string(newS);

            if(j == 5){
                break;
            }else{
                j++;
            }
        }
        return s[0] == s[1];
    }
};
int main (){
    string s = "919";
    auto obj = new Solution();
    cout<<obj->hasSameDigits(s)<<endl;
    cout<<10%10;
    return 0;
}