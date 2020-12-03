class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v(n);
        int start = - n / 2;
        for (int i = 0; i < n; i++) {
            v[i] = start;
            start += 1;
            
            if (!(n & 1) && start == 0) {
                start += 1;
            }
        }
        
        return v;
    }
};