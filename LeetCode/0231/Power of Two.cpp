//Explanation: In binary form, power of two always has a leading 1 and the rest are 0
//             Use & operator, it should return all 0 if n is a power of two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n-1)));
    }
};