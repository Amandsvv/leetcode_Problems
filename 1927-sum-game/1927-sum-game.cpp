class Solution {
public:
    bool sumGame(string num) {
        int left_cnt_mark = 0, right_cnt_mark = 0;
        int left_sum = 0, right_sum = 0, n = num.length();
        int mid = n / 2;

        for (int i = 0; i < n; i++) {
            char ch = num[i];
            if (i < mid) {
                if (ch == '?')
                    left_cnt_mark++;
                else
                    left_sum += (ch - '0');
            } else {
                if (ch == '?')
                    right_cnt_mark++;
                else
                    right_sum += (ch - '0');
            }
        }

        int mark_diff = left_cnt_mark - right_cnt_mark;
        if(mark_diff % 2 != 0) return true;

        if(mark_diff == 0){
            return left_sum != right_sum;
        }

        if(mark_diff > 0){
            int needed_diff = (mark_diff / 2) * 9;
            return (right_sum - left_sum) != needed_diff;
        }

        int needed_diff = (-mark_diff / 2) * 9;
        return (left_sum - right_sum) != needed_diff;
    }
};