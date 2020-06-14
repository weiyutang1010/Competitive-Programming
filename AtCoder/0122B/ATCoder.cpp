#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 

void solve() {
    string s;
    cin >> s;

    vector<char> c {'A', 'C', 'G', 'T'};

    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (find(c.begin(), c.end(), s[i]) != c.end()) {
            int len = 1;
            for (int j = i + 1; j < (int)s.size(); j++) {
                if (find(c.begin(), c.end(), s[j]) != c.end()) {
                    len++;
                } else {
                    break;
                }
            }
            ans = max(ans, len);
        }
    }

    cout << ans << endl;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
