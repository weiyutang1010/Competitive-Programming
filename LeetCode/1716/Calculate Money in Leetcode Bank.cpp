class Solution {
public:
    int totalMoney(int n) {
        int weeks = ceil(n / 7.0);
        int ans = 0;
        for (int i = 1; i < weeks; i++) {
            ans += ((7 + i) * (7 + i - 1) / 2) - (i * (i - 1) / 2);
        }
        int num = (n % 7 == 0? 7 : n % 7);
        ans += ((num + weeks) * (num + weeks - 1) / 2) - (weeks * (weeks - 1) / 2);
        return ans;
    }
};