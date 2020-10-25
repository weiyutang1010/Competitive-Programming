class Solution {
public:
    string removeDuplicates(string S) {
        int n = S.size();
        
        stack<char> st;
        
        function<char ()> word = [&] () -> char {
            if (st.size() < 2) {
                return 0;
            }
            
            string res = "";
            
            res += st.top();
            st.pop();
            res += st.top();
            st.pop();
            reverse(res.begin(), res.end());
            
            st.push(res[0]);
            st.push(res[1]);
            return res[0];
        };
        
        for (int i = 0; i < n; i++) {
            st.push(S[i]);
            if (word() == st.top()) {
                st.pop();
                st.pop();
            }
        }
        
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};