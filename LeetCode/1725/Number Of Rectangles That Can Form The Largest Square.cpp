class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int, int> m;
        int max_len = 0;
        for (int i = 0; i < (int)rectangles.size(); i++) {
            int sz = min(rectangles[i][0], rectangles[i][1]);
            m[sz]++;
            max_len = max(max_len, sz);
        }
        
        return m[max_len];
    }
};