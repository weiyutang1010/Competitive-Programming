class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (int &x: nums) {
            if (m[x]) {
                return true;
            }
            m[x] = true;
        }
        return false;
    }
};