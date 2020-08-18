class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> v(A.size());
        int lt = 0, rt = A.size() - 1;
        int idx = rt;
        
        while (rt >= lt) {
            if (abs(A[lt]) > abs(A[rt])) {
                v[idx] = A[lt] * A[lt];
                lt++;
            } else {
                v[idx] = A[rt] * A[rt];
                rt--;
            }
            idx--;
        }
        
        return v;
    }
};