class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_map<char, bool> m {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
        int count1 = 0, count2 = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] >= 65 && s[i] <= 90)
                s[i] += 'a' - 'A';
            if (m[s[i]]) {
                if (i < (int)s.size() / 2) {
                    count1++;
                } else {
                    count2++;
                }
            }
        }
        return count1 == count2;
    }
};