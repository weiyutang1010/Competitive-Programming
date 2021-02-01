class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> box;
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int n = i, val = 0;
            while (n >= 1) {
                val += n % 10;
                n /= 10;
            }
            box[val]++;
            ans = max(ans, box[val]);
        }
        return ans;
    }
};