#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;

    // for(int i = 0; i < nums1.size(); i++){
    //     int pos = distance(nums2.begin(), find(nums2.begin(), nums2.end(), nums1[i]));

    //     if( pos+1 < nums2.size() && nums2[pos+1] > nums2[pos]){
    //         ans.push_back(nums2[pos+1]);
    //     }else{
    //         ans.push_back(-1);
    //     }
    // }

    for (int i = 0; i < nums1.size(); i++)
    {
        int j = distance(nums2.begin(), find(nums2.begin(), nums2.end(), nums1[i]));

        while (j < nums2.size())
        {
            if (nums2[j] > nums1[i])
            {
                ans.push_back(nums2[j]);
                break;
            }
            j++;
        }
        if (j == nums2.size())
        {
            ans.push_back(-1);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1,nums2);

    for(int el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
}