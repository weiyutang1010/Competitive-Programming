class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for (int& x: time) {
            x %= 60;
        }
        
        for (auto x: time) {
            cout << x << " ";
        }
        cout << endl;
        
        map<int, int> count;
        for (int i = 0; i < (int)time.size(); i++) {
            count[time[i]]++;
        }
        
        int ans = 0;
        for (int i = 1; i <= 29; i++) {
            ans += count[i] * count[60 - i];
        }
        
        ans += (count[0] * (count[0] - 1)) / 2;
        ans += (count[30] * (count[30] - 1)) / 2;
        
        return ans;
    }
};