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
    int ans = 0;
    int post_order(TreeNode* node) {
        if (!node) return 0;
        int val1 = post_order(node->left);
        int val2 = post_order(node->right);
        
        ans += abs(val1 - val2);
        return val1 + val2 + node->val;
        
    }
    
    int findTilt(TreeNode* root) {
        post_order(root);
        return ans;
    }
};