#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void bfs(TreeNode* root, int tar, vector<vector<int>>& ans, vector<int> & temp){
        if(!root)return;
        tar-=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && tar == 0){
            ans.push_back(temp);
        }
        bfs(root->left,tar,ans,temp);
        bfs(root->right,tar,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans = {};
       vector<int> temp = {};
       bfs(root, targetSum, ans, temp);
       return ans; 
    }
};
int main (){

}