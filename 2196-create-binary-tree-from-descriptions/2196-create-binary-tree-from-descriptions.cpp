/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(int val, unordered_map<int, int>& parentLeft, unordered_map<int,int>& parentRight){
        TreeNode* root = new TreeNode(val);

        if(parentLeft.count(val)){
            root->left = construct(parentLeft[val], parentLeft, parentRight);
        }
        if(parentRight.count(val)){
            root->right = construct(parentRight[val], parentLeft, parentRight);
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> parentLeftChild;
        unordered_map<int,int> parentRightChild;
        unordered_set<int> child;

        for(auto& vec : descriptions){
            if(vec[2] == 1){
                parentLeftChild[vec[0]] = vec[1];
            }else{
                parentRightChild[vec[0]] = vec[1];
            }
            child.insert(vec[1]);
        }

        int val = -1;
        for(auto & vec : descriptions){
            if(child.find(vec[0]) == child.end()) {
                val = vec[0];
                break;
            }
        }

        return construct(val, parentLeftChild, parentRightChild);
    }
};