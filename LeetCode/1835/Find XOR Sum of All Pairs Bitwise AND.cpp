class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        // Distributive property
        // (a1 ^ a2) & (b1 ^ b2) = (a1 & b1) ^ (a1 & b2) ^ (a2 & b1) ^ (a2 & b2)
        int n = arr1.size(), m = arr2.size();
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < n; i++) {
            xor1 ^= arr1[i];
        }
        for (int i = 0; i < m; i++) {
            xor2 ^= arr2[i];
        }
        return xor1 & xor2;
    }
};