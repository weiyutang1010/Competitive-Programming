class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26);
        int n = sentence.size();
        int ans = 0;
        for (char& c: sentence) {
            if (v[c - 'a'] == 0) {
                v[c - 'a'] = 1;
                ans++;
            }
        }
        return ans == 26;
    }
};