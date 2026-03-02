#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRight(n, -1);

        for (int i = 0; i < n; ++i) {
            // Scan each row from right to left
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    maxRight[i] = j; // Store the index
                    break;           // Move to the next row immediately
                }
            }
        }
        
        int ans = 0;
        for(int i  = 0; i < n; i++){
            int j = i;

            while(j < n && maxRight[j] > i) j++;

            if(j == n) return -1;

            while(j > i){
                swap(maxRight[j], maxRight[j-1]);
                ans++;
                j--;
            }
        }
        return ans;
    }
};
int main (){

}