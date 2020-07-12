/*
* author: weiyutang
*         Wei Yu Tang 
*/

#include <bits/stdc++.h>

#define ll long long
#define ulli unsigned long long int
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

using namespace std; 

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    bool alice_win = false;
    for (int i = 0; i < (int)(n/2); i++) { //turn
        bool skip = true;
        for (int j = 1; j < (int)s.size(); j++) { //loop through characters
            if (s[j] != s[j-1]) {
                s.erase(j - 1, 2);
                alice_win = !(i % 2);
                skip = false;
                break;
            }
        }
        //cout << s << endl;
        if(skip) break;
    }

    cout << ((alice_win) ? "DA" : "NET") << endl;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
