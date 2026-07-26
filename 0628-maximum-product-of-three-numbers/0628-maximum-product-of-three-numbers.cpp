class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int small1 = INT_MAX, small2 = INT_MAX;
        int a = INT_MIN, b=INT_MIN, c=INT_MIN;
        for(const auto & val : nums){ 
            if(val > a && val > b && val >= c){
                a = b;
                b = c;
                c = val;
            }else if (val > a && val >= b){
                a = b;
                b = val;
            }else if(val > a){
                a = val;
            }

            if(val < small1 && val <= small2){
                small1 = small2;
                small2 = val;
            }else if(val < small1){
                small1 = val;
            }
        } 
        return max((a*b*c), (small1*small2*c));
    }
};