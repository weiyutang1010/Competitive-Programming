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
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
 
void solve() {
    ll a,b;
    int count = 0;
    cin >> a >> b;
    
    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    //If a is smaller than target then we multiply else we divide that number
    //If a is not a multiply of 2 then we cannot find it. Same for division.
    //If a*8 is smaller than target, we keep searching if we can reach that number.
    //Count how many steps it takes
    while (true) {
        if (a < b) {
            if(a * 8 <= b) {
                a *= 8;
            } else if (a * 4 == b) {
                a *= 4;
            } else if (a * 2 == b) {
                a *= 2;
            } else {
                cout << -1 << "\n";
                return;
            }
        } else {
            if (a % 8 == 0 && (a / 8) >= b) {
                a /= 8;
            } else if (a % 4 == 0 && a / 4 == b) {
                a /= 4;
            } else if (a % 2 == 0 && a / 2 == b) {
                a /= 2;
            } else {
                cout << -1 << "\n";
                return;
            }
        }
        count++;
        if (a == b) {
            break;
        }
    }
    cout << count << "\n";
}