class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1) {
            return true;
        }
        
        bool first_lower = (word[0] >= 'a' && word[0] <= 'z');
        if (first_lower) {
            for (int i = 1; i < (int)word.size(); i++) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    return false;
                }
            }
            return true;
        } else {
            bool second_lower = (word[1] >= 'a' && word[1] <= 'z');
            for (int i = 2; i < (int)word.size(); i++) {
                if ((word[i] >= 'a' && word[i] <= 'z') != second_lower) {
                    return false;
                } 
            }
            return true;
        }
        return true;
    }
};