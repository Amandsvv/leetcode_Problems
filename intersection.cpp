#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int n1 = nums1.size() - 1;
    int n2 = nums2.size() - 1;

    int i = n1, j = n2, k = 0;

    while (i >= 0 && j >= 0)
    {
        if(i < n1 && nums1[i] == nums1[i+1]){
            i--;
            continue;
        }

        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i--;
            j--;
        }
        else if (nums1[i] > nums2[j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums1 = {1, 4, 5, 9, 9};
    vector<int> nums2 = {4, 4, 8, 9, 9, 10};

    vector<int> ans = intersection(nums1, nums2);

    for (int el : ans)
    {
        cout << el << " ";
    }

    return 0;
}