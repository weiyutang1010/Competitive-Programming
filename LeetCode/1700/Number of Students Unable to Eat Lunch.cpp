class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sw;
        queue<int> st;
        
        for (int i = 0; i < sandwiches.size(); i++) {
            sw.push(sandwiches[sandwiches.size() - i - 1]);
            st.push(students[i]);
        }
        
        int num = st.size();
        while (!sw.empty() && num > 0) {
            if (st.front() == sw.top()) {
                st.pop();
                sw.pop();
                num = st.size();
            } else {
                st.push(st.front());
                st.pop();
                num--;
            }
        }
        
        return st.size();
    }
};