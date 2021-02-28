class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = 0;
        if (ruleKey == "type") idx = 0;
        else if (ruleKey == "color") idx = 1;
        else idx = 2;
        
        int count = 0;
        int n = items.size();
        for (int i = 0; i < n; i++) {
            if (items[i][idx] == ruleValue) {
                count++;
            }
        }
        
        return count;
    }
};