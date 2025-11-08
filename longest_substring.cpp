#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubS = 0, currSubS = 0;
        unordered_set<char> ch;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (ch.find(s[j]) != ch.end()) {
                    maxSubS = max(maxSubS, currSubS);
                    ch.clear();
                    currSubS = 0;
                    cout<<endl;
                    break;
                } else {
                    ch.insert(s[j]);
                    currSubS++;
                    cout<<"Character : "<<s[j]<<" Max : "<<currSubS<<endl;
                }
            }
        }
        return max(maxSubS, currSubS);
    }
};
int main (){
    string s = "jbpnbwwd";
    auto obj = Solution();
    cout<<obj.lengthOfLongestSubstring(s)<<endl;
}