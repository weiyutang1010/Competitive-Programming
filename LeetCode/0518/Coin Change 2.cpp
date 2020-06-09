class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> combination(amount + 1);
        combination[0] = 1;
        
        for (auto c: coins) {
            for (int i = 1; i < amount + 1; i++) {
                if (i >= c) {
                    combination[i] += combination[i - c];
                }
            }
        }
        
        return combination[amount];
    }
};