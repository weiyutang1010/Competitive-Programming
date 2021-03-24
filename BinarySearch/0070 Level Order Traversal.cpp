/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    vector<int> ans;
    queue<Tree*> Q;
    if (root) {
        Q.push(root);
        while(!Q.empty()) {
            Tree* node = Q.front();
            Q.pop();
            ans.push_back(node->val);
            if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
        }
    }
    return ans;
}