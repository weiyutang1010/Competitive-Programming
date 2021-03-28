class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& v: knowledge) {
            mp[v[0]] = v[1];
        }
        
        string ans = "";
        string key = "";
        int n = s.size();
        bool in_bracket = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') in_bracket = true;
            else if (s[i] == ')') {
                if (mp.find(key) == mp.end()) {
                    ans += '?';
                } else {
                    ans += mp[key];
                }
                key = "";
                in_bracket = false;
            }
            else {
                if (in_bracket) {
                    key += s[i];
                } else {
                    ans += s[i];
                }
            }
        }
        
        return ans;
    }
};