class Solution {
public:
    int trailingZeroes(int n) {
        
        int ans = 0;   // This will store the total number of trailing zeroes
        
        // We keep dividing n by 5, 25, 125... to count factors of 5
        while (n > 0) {
            
            n = n / 5;     // Count how many numbers are divisible by 5
                          // First time: n/5  → multiples of 5
                          // Second time: n/25 → extra 5s from 25, 50, 75...
                          // Third time: n/125 → extra 5s from 125...
            
            ans += n;     // Add this count to answer
        }
        
        return ans;       // Return total trailing zeroes
    }
};
