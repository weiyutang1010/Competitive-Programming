#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        bool count1 = count(moves.begin(), moves.end(), 'U') == count(moves.begin(), moves.end(), 'D');
        bool count2 = count(moves.begin(), moves.end(), 'L') == count(moves.begin(), moves.end(), 'R');
        return count1 && count2;
    }
};