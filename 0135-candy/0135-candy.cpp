class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);

        //left->right (assign candy)
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1] + 1;
            }
        }
        //right -> left (assign candy)
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candy[i] = max(candy[i], candy[i+1] + 1);
            }
        }
        int ans = 0;
        for(int&el : candy) ans+=el;
        return ans;
    }
};