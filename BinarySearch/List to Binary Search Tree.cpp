/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* build(vector<int>& nums, int l, int r) {
    if (l <= r) {
        int mid = l + (r - l + 1) / 2;

        Tree* node = new Tree;
        node->val = nums[mid];

        node->left = build(nums, l, mid-1);
        node->right = build(nums, mid+1, r);

        return node;
    }
    return NULL;
}

Tree* solve(vector<int>& nums) {
    int n = nums.size();
    return build(nums, 0, n-1);
}
