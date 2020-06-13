#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> bin;
        
        if (k > s.size()) {
            return false;
        }
        
        for (int i = 0; i < s.size() - k + 1; i++) {
            bin.insert(s.substr(i,k));
        }
        
        if (bin.size() == pow(2, k)) {
            return true;
        }
        return false;
    }
};