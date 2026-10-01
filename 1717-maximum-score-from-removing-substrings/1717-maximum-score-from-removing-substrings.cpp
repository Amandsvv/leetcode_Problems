class Solution {
public:
    int maximumGain(string s, int x, int y) {
        auto addScore = [&s](string str, int score) {
            int res = 0;
            string stk;
            for (char ch : s) {
                if (!stk.empty() && ch == str[1] && stk.back() == str[0]) {
                    stk.pop_back();
                    res += score;
                } else {
                    stk.push_back(ch);
                }
            }
            s = stk;
            return res;
        };
        int res = 0;
        if (x > y) {
            res += addScore("ab", x);
            res += addScore("ba", y);
        } else {
            res += addScore("ba", y);
            res += addScore("ab", x);
        }
        return res;
    }
};