class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        
        vector<char> v;
        
        v.push_back(letters[0]);
        for (int i = 1; i < n; i++) {
            if (letters[i] != letters[i - 1]) {
                v.push_back(letters[i]);
            }
        }
        v.push_back(letters[0]);
        
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == target) {
                return v[i+1];
            } else if (v[i] > target) {
                return v[i];
            }
        }
        return v[v.size() - 1];
    }
};