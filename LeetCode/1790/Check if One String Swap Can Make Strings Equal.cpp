class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        
        // Check different in characters
        map<char, int> mp1, mp2;
        for (int i = 0; i < n; i++) {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        
        for (auto& x: mp1) {
            if (x.second != mp2[x.first]) {
                return false;
            }
        }
        
        // Check different in order
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) diff++;
        }
        
        return diff <= 2;
    }
};