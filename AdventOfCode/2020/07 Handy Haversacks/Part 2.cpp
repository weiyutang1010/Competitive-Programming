/*
* author: weiyutang
*         Wei Yu Tang 
*/
 
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"
 
using namespace std; 
 
const int MOD = 1e9 + 7;

int main() 
{
    ifstream text("input.txt");
    vector<string> v;
    string st;

    while (getline(cin , st)) {
        v.push_back(st);
    }

    map<string, vector<pair<int,string>>> m;
    string delimiter = " contain ";
    string comma = ", ";
    for (auto st: v) {
        // Process input, create graph
        int pos = st.find(delimiter);
        string key = st.substr(0, pos);
        key.erase(key.size() -1);
        
        st.erase(0, pos + delimiter.size());
        while (st.size()) {
            pos = st.find(comma);
            if (pos == -1) {
                // When string ends with '.'
                st.erase(st.size() - 1);
                if (st[st.size() - 1] == 's') {
                    st.erase(st.size() - 1, 1);
                }
                int quantity = (st[0] == 'n' ? 0: stoi(st.substr(0, 1)));
                m[key].push_back(make_pair(quantity, st.substr(2)));
                st.clear();
            } else {
                // When string ends with ', '
                if (st[pos - 1] == 's') {
                    st.erase(pos - 1, 1);
                    pos--;
                }
               
                int quantity = (st[0] == 'n' ? 0: stoi(st.substr(0, 1)));
                m[key].push_back(make_pair(quantity, st.substr(2, pos - 2)));
                
                st.erase(0, pos + 2);
            }
        }
    }

    function<int64_t (string st)> dfs = [&] (string st) -> int64_t {
        if (st[0] == ' ') {
            return 0;
        }
        int64_t val = 0;
        for (auto x: m[st]) {
            val += x.f + (x.f * dfs(x.s));
        }
        
        return val;
    };

    int64_t ans = dfs("shiny gold bag");
    cout << ans << endl;

    text.close();
    return 0;
} 
