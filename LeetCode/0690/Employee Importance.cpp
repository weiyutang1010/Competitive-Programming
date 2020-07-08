/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int index = 0;
        for (int i = 0; i < (int)employees.size(); i++) {
            if (employees[i]->id == id) {
                index = i;
            }
        }
        
        int sum = employees[index]->importance;
        
        for (int x: employees[index]->subordinates) {
            sum += getImportance(employees, x);
        }
        
        return sum;
    }
};