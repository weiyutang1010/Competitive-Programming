/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    //Perform normal binary search
    //guess() tells if number is high or lower then current element
    int guessNumber(int n) {
        int left = 0;
        int right = n;
        
        while (right >= left) {
            int mid = left + (right - left) / 2;
            
            if (guess(mid) == 0) { 
                return mid;
            }
            
            if (guess(mid) < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};