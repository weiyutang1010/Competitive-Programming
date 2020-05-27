#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int counter = 1;
        priority_queue<int> max_heap;
        
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                max_heap.push(matrix[i][j]);
                if (max_heap.size() > k) {
                    max_heap.pop();
                }
                counter++;
            }
        }
        return max_heap.top();
    }
};