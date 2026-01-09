#include<iostream>
#include<vector>
#include<unordered_set>
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
    bool dfs(TreeNode* root, int k, unordered_set<int>& num){
        if(!root) return false;
        if(num.count(k - root->val)){
            return true;
        };
        num.insert(root->val);
        return dfs(root->left, k, num) || dfs(root->right, k, num);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> num;
        return dfs(root, k, num);
    }
};
int main (){

}