#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1Even, s1Odd, s2Even, s2Odd;

        for(int i = 0; i < s1.size(); i++){
            if(i & 1){
                s1Even += s1[i];
                s2Even += s2[i];
            }else{
                s2Odd += s2[i];
                s1Odd += s1[i];
            }
        }

        sort(s1Even.begin(), s1Even.end());
        sort(s2Even.begin(), s2Even.end());
        sort(s1Odd.begin(), s1Odd.end());
        sort(s2Odd.begin(), s2Odd.end());

        return s1Even == s2Even && s2Odd == s1Odd;
    }
};

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even_count(26, 0), odd_count(26, 0);
        
        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                even_count[s1[i] - 'a']++;
                even_count[s2[i] - 'a']--;
            } else {
                odd_count[s1[i] - 'a']++;
                odd_count[s2[i] - 'a']--;
            }
        }
        
        // Check if all counts are zero
        for (int i = 0; i < 26; i++) {
            if (even_count[i] != 0 || odd_count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main (){

}