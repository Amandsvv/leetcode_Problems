class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int x = n;
        while(x){
            int dig = x%10;
            sum+=dig; pro*=dig;
            x/=10;
        }

        return n % (sum + pro) == 0;
    }
};