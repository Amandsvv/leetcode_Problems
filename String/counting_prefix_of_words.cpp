#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), count = 0;

        for(string word: words){
            if(word.size() >= n){
                if(pref == word.substr(0,n)) count++;
            }
        }

        return count;
    }
};

int main (){
    Solution obj;
    vector<string> words = {"pay","attention","practice","attend"}; 
    string pref = "at";
    cout<<obj.prefixCount(words,pref)<<endl;
}