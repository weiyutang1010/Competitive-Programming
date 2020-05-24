#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string word = countAndSay(n-1);
        string new_word = "";
        int count = 1;
        
        for (int i = 0; i < word.size() - 1; i++) {
            if (word.size() > 1 && word[i+1] != word[i]) {
                new_word += to_string(count);
                new_word += word[i];
                count = 1;
            } else {
                count++;
            }
        }
        new_word += to_string(count);
        new_word += word[word.size() - 1];
        
        return new_word;
        
    }
};