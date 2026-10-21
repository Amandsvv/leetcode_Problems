class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n <= 1) return 0;

        char min_ch = s[0];
        char max_ch = s[0];

        bool isSorted = true;

        for(int i = 1; i < n; i++){
            if(s[i] < s[i-1]) isSorted = false;
            if(s[i] < min_ch) min_ch = s[i];
            if(s[i] > max_ch) max_ch = s[i];
        }

        if(isSorted) return 0;
        if(n == 2) return -1;
        
        if(min_ch == s[0] || max_ch == s[n-1]) return 1;

        if(min_ch == s[n-1] && max_ch == s[0]){
            bool int_min = false;
            bool int_max = false;


            for(int i = 1; i < n-1; i++){
                if(s[i] == min_ch) int_min = true;
                if(s[i] == max_ch) int_max = true;
            }

            if(!int_min && !int_max){
                return 3;
            }
        }

        return 2;

    }
};