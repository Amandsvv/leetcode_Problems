class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // First -> Land Ride  : Than -> Water Ride

        int minTimeTakenLand = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();

        for(int i = 0; i < n; i++){
            minTimeTakenLand = min(minTimeTakenLand, (landStartTime[i] + landDuration[i]));
        }

        int ans = INT_MAX;
        for(int j = 0; j < m; j++){
            ans  = min(ans, (max(minTimeTakenLand, waterStartTime[j]) + waterDuration[j]));
        }

        //First -> water Ride : Than -> Land Ride
        int minTimeTakenWater = INT_MAX;
        for(int j = 0; j < m; j ++){
            minTimeTakenWater = min(minTimeTakenWater, (waterStartTime[j] + waterDuration[j]));
        }

        for(int i = 0; i < n; i++){
            ans = min(ans, (max(minTimeTakenWater, landStartTime[i]) + landDuration[i]));
        }
        return ans;
    }
};