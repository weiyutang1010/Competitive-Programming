class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        // Find mismatch index and swap them
        for (int i = 0; i < (int)A.size(); i++) {
            if ((A[i] & 1) != (i & 1)) {
                for (int j = i + 1; j < (int)A.size(); j += 2) {
                    if ((A[i] & 1) != (A[j] & 1)) {
                        int temp = A[i];
                        A[i] = A[j];
                        A[j] = temp;
                        break;
                    }
                }
            }
        }
        
        return A;
    }
};