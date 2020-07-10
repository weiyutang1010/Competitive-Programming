#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 
void solve(); 
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

//The number must starts with 1. If we see 4 on the next one, we skip it.
//If the last one is 4, we do the same check again.
//Check if the next number is 1.
//If loop till the end then it is a magic number.

void solve() {
    string num;
    cin >> num;

    for (int i = 0; i < num.size(); i++) {
        if (num[i] != '1') {
            cout << "NO\n";
            return;
        }

        if (i + 1 < num.size() && num[i+1] == '4') {
            i++;
            if (i + 1 < num.size() && num[i+1] == '4') {
                i++;
            }
        }
    }
    cout << "YES\n";

}
