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
    int dfs(TreeNode* node, int depth) {
        if (!node) {
            return depth;
        }
        
        return max(dfs(node->left, depth + 1), dfs(node->right, depth + 1));
    }
    
    int maxDepth(TreeNode* root) {
        if (root) {
            return dfs(root, 0);
        }
        return 0;
    }
};