/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
Tree* solve(LLNode* node) {
    if (!node) return NULL;

    Tree* root = new Tree;
    root->val = node->val;
    if (node) {
        Tree* temp = root;
        node = node->next;
        while (node != NULL) {
            // Check if the node should be left or right child
            if (node->val < temp->val) {
                temp->left = new Tree;
                temp->left->val = node->val;
                temp = temp->left;
            } else {
                temp->right = new Tree;
                temp->right->val = node->val;
                temp = temp->right;
            }
            node = node->next;
        }
    }
    return root;
}