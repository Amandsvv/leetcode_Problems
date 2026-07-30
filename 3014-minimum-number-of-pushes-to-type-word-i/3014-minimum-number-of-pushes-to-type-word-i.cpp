class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        // vector<int> freq(26, 0);
        // for(char ch : word){
        //     freq[ch-'a']++;
        // }
        int n = word.size();
        int div = n / 8;
        int rem = n % 8;

        if(div == 0){
            return rem;
        }else if(div == 1){
            return 8 + (rem * 2);
        }else if(div == 2){
            return 8 + 16 + (rem * 3);
        }else{
            return 8 + 16 + 24 + (rem * 4);
        }
        return 0;
    }
};