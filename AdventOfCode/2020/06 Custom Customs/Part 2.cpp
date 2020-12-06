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
    string st;
    map<char, int> m;

    int num_pl = 0;
    int ans = 0;
    while (getline(cin , st)) {
        if (st[0] == 0) {
            for (auto x: m) {
                if (x.s == num_pl) {ans++;}
            }
            num_pl = 0;
            m.clear();
            continue;
        }
        for (int i = 0; i < (int)st.size(); i++) {
            m[st[i]] += 1;
        }
        num_pl++;
    }

    cout << ans << endl;
    text.close();
    return 0;
} 
