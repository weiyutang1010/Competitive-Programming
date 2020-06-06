class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }
        
        int left = 0;
        int right = x/2;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if ((mid * mid) <= x && (mid + 1) * (mid + 1) > x) { //check if target is between current number squared and next number squared
                return mid;
            }
            
            if (mid * mid < x) { //perform normal binary search
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};