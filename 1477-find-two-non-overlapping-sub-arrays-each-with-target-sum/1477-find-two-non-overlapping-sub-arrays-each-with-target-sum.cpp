class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int currSum = 0;
        // left && right maintains a winfow to define the length here 
        // Minlen:  stores minLen found till now to tell minimum length ehich can be seen before or till i in dp[i]
        // ans: calculates such two sub arrays with addition of currLEn + minLen before this
        int left = 0, minLen = INT_MAX, ans = INT_MAX;
        // dp
        int sz = arr.size();
        vector<int> dp(sz, INT_MAX); 

        for(int right = 0; right < arr.size(); right++){
            currSum+=arr[right]; // global sum 
            while(currSum > target){ // keeping frame only where sum is <= target
                currSum -= arr[left];
                left++;
            }
            if(currSum == target){
                int len = right - left + 1; // calculates length 

                if(left > 0 && dp[left - 1] != INT_MAX){ // check is there any minlen we may get before this
                    ans = min(ans, len + dp[left - 1]); // if yes calculate the sum of these two lengths
                }

                minLen = min(len, minLen); // maintain the global minimum length found till here
            }

            dp[right] = minLen; // store it inside the dp for later use
        }
       
        return ans == INT_MAX ? -1 : ans; // check can we find such two subarray or not
    }
};