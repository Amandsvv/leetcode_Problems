class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        // -3, -4, 3, 3, 9 + 16 + 9 + 9
        int sz = nums1.size();
        vector<long long> diff(sz);
        long long total_diff = 0;

        for (int i = 0; i < sz; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total_diff += diff[i];
        }

        sort(diff.begin(), diff.end(), greater<long long>());

        long long dcr = (long long)k1 + k2;
        int i = 0;
        if (dcr >= total_diff)
            return 0;
        diff.push_back(0);

        while (dcr != 0 && i < sz) {
            long long count = i + 1;
            long long gap = diff[i] - diff[i + 1];
            long long needed = count * gap;

            if (dcr >= needed) {
                dcr -= needed;
                i++;
            }else{
                long long dec = dcr / count;
                long long rem = dcr % count;

                long long target = diff[i] - dec;
                for(int j = 0; j < count; j++){
                    diff[j] = target - (j < rem ? 1 : 0); 
                }
                dcr = 0;
                break;
            }
        }

        long long ans = 0;
        for(int j = 0; j < sz; j++){
            // Fill any elements up to i that were flattened during full-step iterations
            if (j <= i && dcr == 0 && diff[j] > diff[i]) {
                diff[j] = diff[i];
            }
            ans += diff[j] * diff[j];
        }
        return ans;
    }
};