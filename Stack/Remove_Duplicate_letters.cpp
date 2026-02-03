#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string str = "";
        vector<int> seen(26,0), freq(26,0);

        for(char ch : s)freq[ch - 'a']++;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            freq[ch - 'a']--;
            if(seen[ch-'a'])continue;

            while(str.size() > 0 && str.back() > ch && freq[str.back() - 'a'] != 0){
                seen[str.back() - 'a'] = 0;
                str.pop_back();
            }

            seen[ch - 'a'] = 1;
            str.push_back(ch);
        }

        return str;
    }
};
int main (){

}