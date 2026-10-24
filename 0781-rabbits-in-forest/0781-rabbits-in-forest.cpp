class Solution {
public:
    int numRabbits(vector<int>& answers) {
        //
        unordered_map<int, int> uniq;
        for (auto& ans : answers) {
            uniq[ans]++;
        }
        int res = 0;
        for (auto& pairCnt : uniq) {
            auto a = pairCnt.first;
            auto b = pairCnt.second;
            if (a == 0) {
                res += b;
            } else{
                int grpSz = a + 1;
                int grps = (b + grpSz - 1) / grpSz;
                res += (grps * grpSz);
            }
        }
        return res;
    }
};