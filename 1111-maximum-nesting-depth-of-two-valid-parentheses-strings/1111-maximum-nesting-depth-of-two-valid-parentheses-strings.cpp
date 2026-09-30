class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int sz = seq.size();
        vector<int> ans(sz, 0);
        // stack<pair<char, int>> stk;
        // for (int i = 0; i < sz; i++) {
        //     char ch = seq[i];
        //     if (ch == '(') {
        //         // check it and alternate it
        //         if (!stk.empty()) {
        //             auto& p = stk.top();
        //             int idx = p.second;
        //             ans[i] = ans[idx] == 0 ? 1 : 0;
        //         }
        //         stk.push({ch, i});
        //     } else if (ch == ')') {
        //         auto& p = stk.top();
        //         int idx = p.second;
        //         ans[i] = ans[idx];
        //         stk.pop();
        //     }
        // }

        int depth = 0;
        for(int i = 0; i < sz; i++){
            char ch = seq[i];
            if(ch == '('){
                ans[i] = depth % 2;
                depth++;
            }else{
                depth--;
                ans[i] = depth % 2;
            }
        }
        return ans;
    }
};