class Solution {
public:
    void func(vector<char>& s, int c1, int c2) {
        if (c2 <= c1) return;
        
        char temp = s[c1];
        s[c1] = s[c2];
        s[c2] = temp;
        func(s, c1+1, c2-1);
    }
    
    void reverseString(vector<char>& s) {
        func(s, 0, s.size() - 1);
    }
};