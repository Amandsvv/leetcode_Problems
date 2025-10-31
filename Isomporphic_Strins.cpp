#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,char> iso;
        unordered_map<char,char> iso2;
        for(int i = 0; i <s.size(); i++){
            if(iso.find(s[i]) != iso.end()){
                if(iso[s[i]] != t[i]){
                    return false;
                }
            }
            if(iso2.find(t[i]) != iso2.end()){
                if(iso2[t[i]] != s[i]){
                    return false;
                }
            }

            iso[s[i]] = t[i];
            iso2[t[i]] = s[i];
            
        }
        return true;
    }
};
int main (){
    string s = "egg";
    string t = "add";
}