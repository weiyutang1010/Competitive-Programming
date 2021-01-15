class Solution {
public:
    struct comp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            if (b[1] != a[1]) {
                return b[1] > a[1];
            }
            return b[0] > a[0];
        }
    };
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if ((int)intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), comp());
        
        for (auto x: intervals) {
            cout << x[0] << " " << x[1] << endl;
        }
        
        int ans = 1;
        int lt = intervals[0][0], rt = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] >= rt) {
                rt = intervals[i][1];
                ans++;
            }   
        }
        return intervals.size() - ans;
    }
};