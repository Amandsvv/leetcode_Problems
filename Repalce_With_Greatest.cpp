#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int lar = -1;
        for(int i = n-1; i >= 0; i--){
            int curr = arr[i];
            arr[i] = lar;
            lar = max(curr, lar);
        }
        return arr;
    }
};
int main (){
    vector<int> arr = {17,18,4,5,6,1,-1};
    auto obj = Solution();
    vector<int> ans = obj.replaceElements(arr);
}