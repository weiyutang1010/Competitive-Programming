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
    int maxFreq= 0, currFreq = 0, precursor = INT_MIN;
    vector<int> res;
    
    vector<int> findMode(TreeNode* root) {
        inorder_traversal(root);
        return res;
    }
    
    void inorder_traversal(TreeNode* node) {
        //Base Case
        if (!node) return;
        
        //Travel left subtree
        inorder_traversal(node->left);
        
        //Compare precursor and current value
            //If same then currFreq++
            //Else it is equal to 1
        if (node->val == precursor) {
            currFreq++;
        } else {
            currFreq = 1;
        }
        
        //Compare curr freq and max freq
            //If greater than,
                //Reset res vector
                //Update max freq
                //Push current value
            //If equal, push to res
            
        if (currFreq > maxFreq) {
            res.clear();
            maxFreq = currFreq;
            res.push_back(node->val);
        }
        else if (currFreq == maxFreq) {
            res.push_back(node->val);
        }
        
        //Update precursor value
        precursor = node->val;
        //Travel right subtree
        inorder_traversal(node->right);
    }
};