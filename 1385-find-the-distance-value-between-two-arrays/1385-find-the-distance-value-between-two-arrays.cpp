class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(const auto & a: arr1){
            bool found = true;
            for(auto & b: arr2){
                if(abs(a - b) <= d){
                    found = false;
                    break;
                }
            }
            if(found) cnt++;
        }
        return cnt;
    }
};