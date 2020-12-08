class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row_size = matrix.size(), col_size = matrix[0].size();
        for (int i = row_size - 1, j = 0; i >= 0; i--) {
            int a = i, b = j;
            while (a + 1 < row_size && b + 1 < col_size) {
                if (matrix[a + 1][b + 1] != matrix[a][b]) {
                    return false;
                }
                a++, b++;
            }
        }
        
        for (int i = 0, j = 1; j < col_size; j++) {
            int a = i, b = j;
            while (a + 1 < row_size && b + 1 < col_size) {
                if (matrix[a + 1][b + 1] != matrix[a][b]) {
                    return false;
                }
                a++, b++;
            }
        }
        
        return true;
    }
};  