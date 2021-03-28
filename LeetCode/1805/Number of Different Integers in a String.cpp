class Solution {
public:
    int numDifferentIntegers(string word) {
        int count = 0;
        int n = word.size();
        map<string, int> mp;
        string num = "";
        for (int i = 0; i < n; i++) {
            if (word[i] >= '0' && word[i] <= '9') {
                if (num[0] == '0') {
                    num = word[i];
                } else {
                    num += word[i];
                }
            } else if ((word[i] < '0' || word[i] > '9') && num != "") {
                mp[num] = 1;
                num = "";
            }
        }
        if (num != "") {
            mp[num] = 1;
        }
        return mp.size();
    }
};