//Explanation: As we loop through the the second string, we check if the character is the same as
//             the first character of the first string. If it is, we remove the first letter from
//             the first string.

class Solution {
public:
    bool isSubsequence(string s, string t) {
        for (auto x: t) {
            if (x == s[0]) {
                s.erase(s.begin());
            }
        }
        
        return ((s.size() == 0) ? true : false);
    }
};