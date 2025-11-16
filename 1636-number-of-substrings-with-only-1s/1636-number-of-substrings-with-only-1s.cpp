class Solution {
public:
    int numSub(string s) {
        vector<int> consecutive1;
        const long long MOD = 1e9 + 7;
        long long ans = 0, size = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '1') size++;
            else{
                if(size != 0){
                    consecutive1.push_back(size);
                    size = 0;
                }
            }
        }
        if(size!= 0) consecutive1.push_back(size);

        for(long long el : consecutive1){
            long long contribution = (el + 1)*el/2;
            contribution = contribution % MOD;
            ans = (ans + contribution) % MOD;
        }
        ans = ans % MOD;
        return ans;
    }
};