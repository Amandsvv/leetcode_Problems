class Solution {
public:
    bool helper(int mid, vector<vector<int>> tasks) {
        int currEnergy = mid;
        for (auto& vec : tasks) {
            if (currEnergy < vec[1])
                return false;
            currEnergy -= vec[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int ans;
        int st = 0;
        int end = 0;
        for (vector<int> vec : tasks) {
            st += vec[0];
            end += vec[1];
        }

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (helper(mid, tasks)) {
                end = mid - 1;
                ans = mid;
            } else
                st = mid + 1;
        }

        return ans;
    }
};