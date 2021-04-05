/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void inorder(vector<int>& v, Tree* node) {
    if (node->left) inorder(v, node->left);
    v.push_back(node->val);
    if (node->right) inorder(v, node->right);
}

bool check_palindrome(vector<int>& v) {
    int n = v.size();
    for (int l = 0, r = n-1; l < r; l++, r--) {
        if (v[l] != v[r]) return false;
    }
    return true;
}

bool solve(Tree* root) {
    vector<int> v;
    if (root) {
        inorder(v, root);
        return check_palindrome(v);
    }
    return false;
}