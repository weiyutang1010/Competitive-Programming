class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> m;
        for (char& c: allowed) {
            m[c] = 1;
        }
        
        int ans = 0;
        for (string& word: words) {
            bool valid = true;
            for (char& c: word) {
                if (!m[c]) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) ans++;
        }
        
        return ans;
    }
};