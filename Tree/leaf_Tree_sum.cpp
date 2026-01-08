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
    void dfs(TreeNode* root, int& ans, string num){
        if(!root) return;
        num += char(root->val+'0');
        if(!root->left && !root->right){
            ans += stoi(num);
            return;
        }
        dfs(root->left, ans, num);
        dfs(root->right, ans, num);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root,ans,"");
        return ans;
    }
};

int main (){

}