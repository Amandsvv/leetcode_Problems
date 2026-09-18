class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int, int>> mpRange(26, {-1, -1});
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            int idx = s[i] - 'a';
            if (mpRange[idx].first != -1 && mpRange[idx].second != -1) {
                mpRange[idx].second = i;
            } else {
                mpRange[idx] = {i, i};
            }
        }

        vector<pair<int,int>> ans;
        for (int i = 0; i < sz; i++) {
            int idx = s[i] - 'a';            
            int left = mpRange[idx].first;

            if(left != i) continue;

            int right = mpRange[idx].second;
            bool valid = true;
            for(int j = left; j <= right; j++){
                int curr = s[j] - 'a';

                if(mpRange[curr].first < left){
                    valid = false;
                    break;
                }

                if(mpRange[curr].second > right){
                    right = mpRange[curr].second;
                }
            }

            if(valid){
                ans.push_back({left, right});
            }
        }

        sort(ans.begin(), ans.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });

        int prevEnd = -1;
        vector<string> finalAns;

        for(const auto& intervals : ans){
            if(intervals.first > prevEnd){
                string str = s.substr(intervals.first, intervals.second - intervals.first + 1);
                finalAns.push_back(str);
                prevEnd = intervals.second;
            }
        }
        return finalAns;

    }
};