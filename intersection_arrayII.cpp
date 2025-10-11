#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> ans;
    int idx1 = 0, idx2 = 0;

    while(idx1 < nums1.size() && idx2 < nums2.size()){
        if(nums1[idx1] == nums2[idx2]){
            ans.push_back(nums1[idx1]);
            idx1++; idx2++;
        }else if(nums1[idx1] < nums2[idx2]){
            idx1++;
        }else{
            idx2++;
        }
    }

    return ans;
}
int main(){ 
    vector<int> ans = {1,2,7};
    auto it = find(ans.begin(),ans.end(),7);
    cout<<*(it);
}