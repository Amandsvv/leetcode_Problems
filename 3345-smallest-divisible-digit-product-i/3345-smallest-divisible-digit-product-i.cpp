class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n ; i <= n*t; i++){
            string x = to_string(i);
            int prod = 1;
            for(char & ch : x) prod*=(ch - '0');
            if(prod%t == 0) return i;
        }
        return 0;
    }
};