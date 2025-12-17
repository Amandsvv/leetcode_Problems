#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore(score.begin(),score.end());
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        vector<string> ans;
        for(int i = 0; i < score.size(); i++){
            int pos = distance(sortedScore.begin(),find(sortedScore.begin(), sortedScore.end(), score[i]));
            if(pos == 0){
                ans.push_back("Gold Medal");
            }else if(pos == 1){
                ans.push_back("Silver Medal");
            }else if(pos == 2){
                ans.push_back("Bronze Medal");
            }else{
                ans.push_back(to_string(pos+1));
            }
        }
        return ans;
    }
};
int main (){

}