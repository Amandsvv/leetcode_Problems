class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int drevantor = sum; // store input midway
        if (sum > 9LL * num) return "";
        string res;
        res.reserve(num);
        for (int i = 0; i < num; ++i) {
            int d = min(9, drevantor);
            res.push_back('0' + d);
            drevantor -= d;
        }
        return res;
    }
};
