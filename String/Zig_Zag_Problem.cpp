#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> ans(numRows,"");
        bool right = true, left = false;
        int idx = 0;
        for(int i = 0; i< s.size(); i++){
            if(right){
                ans[idx++]+=s[i];
            }else{
                ans[idx--]+=s[i];
            }
            if(idx == numRows){
                idx-=2;
                right = false; left = true;
            }else if(idx == -1){
                idx+=2;
                right = true; left = false;
            }
        }
        string answer = "";
        for(string s : ans){
            answer+=s;
        }
        return answer;
    }
};
int main (){
    string s = "PAYPALISHIRING";
    Solution obj;
    cout<<obj.convert(s,3)<<endl;
}