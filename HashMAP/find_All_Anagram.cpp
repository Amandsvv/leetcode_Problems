#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans = {};
        int n = s.size();

        unordered_map<char,int> freq;
        for(char ch : p){
            freq[ch]++;
        }

        unordered_map<char,int> seq;
        int i = 0, j = 0;
        for(;j < p.size(); j++){
            seq[s[j]]++;
        }
        if(seq == freq) ans.push_back(0);
        while(j < n){
            seq[s[j]]++;
            seq[s[i]]--;

            if(seq[s[i]] == 0){
                seq.erase(s[i]);
            }
            i++; j++;
            if(seq == freq) ans.push_back(i);
        }
        return ans;
    }
};
int main (){

}