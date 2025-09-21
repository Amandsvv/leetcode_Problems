#include <iostream>
#include <vector>

using namespace std;
bool notIn(vector<int>& A,int tar){
    for(int a : A){
        if(a == tar) return true;
    }
    return false;
}
int thirdMax(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {   
        if(!notIn(ans,nums[i])){
            if (ans.size() == 1 && nums[i] > ans[0])
            {
                int temp = ans[0];
                ans[0] = nums[i];
                ans.push_back(temp);
            }
            else if (ans.size() == 1 && nums[i] < ans[0])
            {
                ans.push_back(nums[i]);
            }
            else if (ans.size() == 2 && nums[i] > ans[0] && nums[i] > ans[1])
            {
                ans.push_back(nums[1]);
                ans[1] = ans[0];
                ans[0] = nums[i];
            }
            else if (ans.size() == 2 && nums[i] < ans[0] && nums[i] > ans[1])
            {
                ans.push_back(nums[1]);
                ans[1] = nums[i];
            }
            else if (ans.size() == 2 && nums[i] < ans[0] && nums[i] < ans[1])
            {
                ans.push_back(nums[i]);
            }
            else if (ans.size() == 3 && nums[i] > ans[0] && nums[i] > ans[1] && nums[i] > ans[2])
            {
                ans[2] = ans[1];
                ans[1] = ans[0];
                ans[0] = nums[i];
            }
            else if (ans.size() == 3 && nums[i] < ans[0] && nums[i] > ans[1] && nums[i] > ans[2])
            {
                ans[2] = ans[1];
                ans[1] = nums[i];
            }
            else if (ans.size() == 3 && nums[i] < ans[0] && nums[i] < ans[1] && nums[i] > ans[2])
            {
                ans[2] = nums[i];
            }
            else
            {
                continue;
            }
        }
       
    }
    return ans[2];
}

int main()
{
    vector<int> A = {-2147483648,1,2};
    cout << thirdMax(A);
    return 0;
}