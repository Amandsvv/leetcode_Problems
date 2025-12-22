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
    void valid(TreeNode* root, int tar, int sum, bool& found){
        if(!root) return;
        sum+=root->val;
        if(!root->left && !root->right && sum == tar){
            found = true;
            return;
        };
        valid(root->left,tar,sum,found);
        valid(root->right,tar,sum,found);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found = false;
        valid(root,targetSum,0,found);
        return found;
    }
};
int main (){

}