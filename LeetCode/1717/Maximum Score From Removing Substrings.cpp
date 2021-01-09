class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if ((int)s.size() < 2) {
            return 0;
        }
        
        stack<char> st;
        pair<string, int> search = (x > y ? make_pair("ab", x) : make_pair("ba", y));
        int ans = 0;
        st.push(s[0]);
        
        for (int i = 1; i < (int)s.size(); i++) {
            st.push(s[i]);
            if (st.size() >= 2) {
                string word = "";
                word += st.top();
                st.pop();
                word += st.top();
                st.push(word[0]);
                reverse(word.begin(), word.end());
                if (word == search.first) {
                    st.pop(); st.pop();
                    ans += search.second;
                }
                word.clear();
            }
        }
        
        stack<char> st2;
        search.second = (search.second == x) ? y : x;
        
        if (st.size() < 2) {
            return ans;
        }
        
        st2.push(st.top()); st.pop();
        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
            
            if (st2.size() >= 2) {
                string word = "";
                word += st2.top();
                st2.pop();
                word += st2.top();
                st2.push(word[0]);
                reverse(word.begin(), word.end());
                if (word == search.first) {
                    st2.pop(); st2.pop();
                    ans += search.second;
                }
                word.clear();
            }
        }

        return ans;
        
    }
};