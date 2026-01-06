#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void findSum(TreeNode* root, int level, vector<int>& levelSum){
        if(!root) return;
        if(level == levelSum.size()) levelSum.push_back(0);
        levelSum[level]+=root->val;
        findSum(root->left, level+1, levelSum);
        findSum(root->right, level+1, levelSum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> levelSum;
        findSum(root,0,levelSum);
        int ans = 0;
        for(int i = 1; i < levelSum.size(); i++){
            if(levelSum[i] > levelSum[ans] ){
                ans = i;
            }
        }
        return ans+1;
    }
};
int main (){

}