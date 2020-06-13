class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> counter;
        for (auto x: target) {
            counter[x]++;
        }
        
        for (auto x: arr) {
            if (counter[x] == 0) {
                return false;
            }
        }
        
        return true;
    }
};