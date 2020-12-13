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
    int n;
    string st;
    cin >> n;
    cin >> st;
    vector<ii> bus;
    int t = 0;
    while (st.size() >= 0) {
        int pos = st.find(',');
        if (st[0] == 'x') {
            st.erase(0, 2);
            t++;
            continue;
        }
        if (pos == -1) {
            bus.push_back({stoi(st.substr(0)), t});
            break;
        }
        bus.push_back({stoi(st.substr(0,pos)), t});
        st.erase(0,pos + 1);
        t++;
    }

    for (int i = n; i < n + 100000; i++) {
        bool found = false;
        for (int j = 0; j < (int)bus.size(); j++) {    
            if (i % bus[j].f == 0) {
                cout << (i - n) * bus[j].f << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    text.close();
    return 0;
} 
