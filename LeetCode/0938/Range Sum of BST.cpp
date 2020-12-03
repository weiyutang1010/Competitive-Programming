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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> Q;
        Q.push(root);
        int sum = 0;
        
        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            
            if (!node) {
                continue;
            }
            
            if (node->val > low) {
                Q.push(node->left);
            }
            
            if (node->val < high) {
                Q.push(node->right);
            }
            
            if (node->val >= low && node->val <= high) {
                sum += node->val;
            }
        }
        
        return sum;
    }
};