//Explanation: Half of the people go A and half go B. We want to find the value that minimizes the cost. 
//             Sort the array by difference in cost between going to A and B. 
//             Now the array is sorted by the value earned by going to A in descending order (B - A).
//             The first half of people go to city A and second half go to city B.

class Solution {
public:
    static bool compare_cost(vector<int> &a, vector<int> &b) {
        return a[1]-a[0] > b[1] - b[0];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        sort(costs.begin(), costs.end(), compare_cost);
        
        for (int i = 0; i < costs.size(); i++) {
            sum += (i < costs.size() / 2) ? costs[i][0] : costs[i][1];
        }
        
        
        
        return sum;
    }
};