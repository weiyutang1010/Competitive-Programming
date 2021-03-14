class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        // pq contains {change in passing rate, num of pass students, total students }
        priority_queue<array<double, 3>, vector<array<double, 3>>> pq;
        
        double curr_rate = 0; // Let curr rate = (a_1 / b_1) + (a_2 / b_2) + ...
        for (int i = 0; i < n; i++) {
            // Let a be number of passing students and b be number of total students in classes[i]
            double a = classes[i][0], b = classes[i][1];
            curr_rate += a / b;
            pq.push({(b - a) / (b * (b + 1)), a, b});
        }
        
        for (int i = 0; i < extraStudents; i++) {
            array<double, 3> curr = pq.top();
            pq.pop();
            double a = curr[1], b = curr[2];
            
            curr_rate -= a / b;
            a++, b++;
            curr_rate += (a / b);
            
            pq.push({(b - a) / (b * (b + 1)), a, b});
        }
        
        return curr_rate / n;
    }
};