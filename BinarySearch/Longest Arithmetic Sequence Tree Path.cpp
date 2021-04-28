/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int ans;

void dfs(Tree* prev, Tree* curr, int last_diff, int len) {
    // Check the difference between curr node and parent node
    // compare them to the difference from previous node

    int curr_diff = curr->val - prev->val;
    if (curr_diff == last_diff) {
        // When the difference are the same, increase length
        len++;
        ans = max(ans, len);
    } else {
        // Reset length to 2
        len = 2;
    }

    // Traverse left and right child if exist
    if (curr->left) {
        dfs(curr, curr->left, curr_diff, len);
    }

    if (curr->right) {
        dfs(curr, curr->right, curr_diff, len);
    }
}

int solve(Tree* root) {
    ans = 1;
    if (root) {
        // Traverse left and right child if exist
        if (root->left) {
            int diff1 = root->left->val - root->val;
            dfs(root, root->left, diff1, 1);
        }

        if (root->right) {
            int diff2 = root->right->val - root->val;
            dfs(root, root->right, diff2, 1);
        }
        return ans;
    } else {
        // when there's no node
        return 0;
    }
}