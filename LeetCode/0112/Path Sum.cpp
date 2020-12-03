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
    bool dfs(TreeNode* root, int curr, int target) {
        curr += root->val;
        bool status = false;
        if (root->left) {
            status = dfs(root->left, curr, target);
        }
        
        if (root->right && !status) {
            status = dfs(root->right, curr, target);
        }
        
        if (!root->left && !root->right) {
            return target == curr;
        }
        
        return status;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        int curr = 0;
        if (root) {
            return dfs(root, curr, sum);
        }
        return false;
    }
};