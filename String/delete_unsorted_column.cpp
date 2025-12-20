#include<iostream>
#include<vector>
using namespace std;
int main (){
    
}
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int dlt = 0;

        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(i < strs[j].size()){
                    if(strs[j-1][i] > strs[j][i]) {
                        dlt++;
                        break;
                    }
                }
            }
        }

        return dlt;
    }
};