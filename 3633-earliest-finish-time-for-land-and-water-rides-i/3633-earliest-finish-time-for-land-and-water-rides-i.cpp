class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for(int i = 0; i < landStartTime.size(); i++){
            int time = landStartTime[i] + landDuration[i];
            for(int j = 0; j < waterStartTime.size(); j++){
                int finish = max(time, waterStartTime[j]) + waterDuration[j];
                ans = min(ans, finish);
            }
        }
        for(int j = 0; j < waterStartTime.size(); j++){
            int time = waterStartTime[j] + waterDuration[j];
            for(int i = 0; i < landStartTime.size(); i++){
              int finish = max(time, landStartTime[i]) + landDuration[i]; 
               ans = min(ans, finish);
            }
        }
        return ans;
    }
};