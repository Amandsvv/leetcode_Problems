class Solution {
public:
    int maxProduct(int n) {
      int a = -1, b = -1;
        while(n){
            int dig = n%10;
            if(dig > a && dig >= b){
                a = b;
                b = dig;
            }else if ( dig > a){
                a = dig;
            }
            n/=10;
        }
        return a * b;
    }
};