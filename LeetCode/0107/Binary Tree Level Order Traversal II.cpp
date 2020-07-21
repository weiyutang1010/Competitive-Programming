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
    vector<vector<int>> res;
    void dfs(TreeNode* node, int level) {
        if (node == NULL) {
            return;
        }
        if (level == (int)res.size()) {
            res.push_back(vector<int> ());
        } 
        res[level].push_back(node->val);
        
        dfs(node->left, level+1);
        dfs(node->right, level + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root, 0);
        return vector<vector<int>> (res.rbegin(),res.rend());
        
    }
};