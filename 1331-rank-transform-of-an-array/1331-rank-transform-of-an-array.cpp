class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copyArr (arr.begin(), arr.end());
        sort(copyArr.begin(), copyArr.end());
        int cnt = 1, n = arr.size();
        unordered_map<int, int> ranks;
        for(int i = 0; i < n; i++){
            if(i > 0)
                if(copyArr[i] != copyArr[i-1]){
                    cnt++;
                }
            ranks[copyArr[i]] = cnt;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(ranks[arr[i]]);
        }
        return ans;
    }
};