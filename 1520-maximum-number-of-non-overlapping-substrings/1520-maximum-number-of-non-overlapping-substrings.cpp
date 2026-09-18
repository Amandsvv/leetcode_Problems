class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, pair<int, int>> mpRange;
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            char ch = s[i];
            if (mpRange.find(ch) != mpRange.end()) {
                mpRange[ch].second = i;
            } else {
                mpRange[ch].first = i;
                mpRange[ch].second = i;
            }
        }

        vector<pair<int,int>> ans;
        for (int i = 0; i < sz; i++) {
            char ch = s[i];            
            int left = mpRange[ch].first;

            if(left != i) continue;

            int right = mpRange[ch].second;
            bool valid = true;
            for(int j = left; j <= right; j++){
                char curr = s[j];

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