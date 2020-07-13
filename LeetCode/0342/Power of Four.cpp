class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num > 1) {
            if (num % 4 == 0) {
                num /= 4;
            } else {
                break;
            }
        }
        
        return num == 1;
    }
};