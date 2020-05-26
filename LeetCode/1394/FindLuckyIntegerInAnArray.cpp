#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> counter;
        int ans = -1;
        for (auto x: arr) {
            counter[x]++;
        }
        
        for (auto x: counter) {
            if (x.first == x.second) {
                ans = max(ans, x.first);
            }
        }
        return (ans == 0) ? -1 : ans;
    }
};