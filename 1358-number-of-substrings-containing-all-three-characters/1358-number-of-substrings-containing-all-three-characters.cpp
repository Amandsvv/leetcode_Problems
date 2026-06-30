class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int ans = 0;
        int a = -1, b = -1, c = -1;
        vector<vector<int>> pos(n);

        for(int i = n-1; i >= 0; i--){
            if(s[i]  == 'a') a = i;
            if(s[i]  == 'b') b = i;
            if(s[i]  == 'c') c = i;
            pos[i] = {a,b,c};
        }
        for(int i= 0; i < n; i++){
            int a = pos[i][0];
            int b = pos[i][1];
            int c = pos[i][2];

            if(a == -1 || b == -1 || c == -1 || a < i || b < i || c < i) continue;
            int lastPos = max({a, b, c});
            ans += (n - lastPos);
        }
        
        return ans;
    }
};