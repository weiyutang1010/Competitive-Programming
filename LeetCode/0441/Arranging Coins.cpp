#define ll long long
class Solution {
public:
    int arrangeCoins(int n) {
        if (n < 1) {
            return 0; 
        }
        
        ll level = 1;
        while (n >= (level * (level + 1)) / 2) {
            level++;
        }
        
        return (level - 1);
    }
};