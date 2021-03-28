class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
        
        int count;
        for (count = 1; count < 1000; count++) {
            vector<int> arr(n, 0);
            for (int i = 0; i < n; i++) {
                if (i % 2) {
                    arr[i] = v[n / 2 + (i - 1) / 2];
                } else {
                    arr[i] = v[i/2];
                }
            }
            v = arr;
            bool found = true;
            for (int i = 0; i < n; i++) {
                if (v[i] != i) {
                    found = false;
                }
            }
            if (found) break;
        }

        return count;
    }
};