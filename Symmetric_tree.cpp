#include<iostream>
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            // Both null - continue
            if (!left && !right) continue;
            
            // One null or values don't match - not symmetric
            if (!left || !right || left->val != right->val) 
                return false;
            
            // Add children in mirror order
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
};
