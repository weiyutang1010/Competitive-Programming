/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root, vector<string>& moves) {
    int n = moves.size();
    stack<Tree*> st;

    Tree* curr = root;
    for (int i = 0; i < n; i++) {
        st.push(curr);

        if (moves[i] == "RIGHT") {
            curr = curr->right;
        } else if (moves[i] == "LEFT") {
            curr = curr->left;
        } else {
            st.pop();
            curr = st.top();
            st.pop();
        }
    }

    return curr->val;
}
