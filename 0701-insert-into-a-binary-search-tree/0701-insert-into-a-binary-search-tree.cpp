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
    void insert(TreeNode* root, int val){
        if(!root) return;
        if((root->left == NULL && root->val > val) || (root->right == NULL && root->val < val) || (root->left == NULL && root->right == NULL)){
            TreeNode* node = new TreeNode(val);
            if(root->val > val){
                root->left = node;
            }else{
                root->right = node;
            }
            return;
        }
        if(root->val > val)insert(root->left, val);
        else insert(root->right, val);

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root= new TreeNode(val);
            return root;
        }
        insert(root, val);
        return root;
    }
};