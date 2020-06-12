#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 

void solve() {
    unsigned int a, b , c;
    
    cin >> a >> b >> c;
    if (a == b && b == c) {
        if (a & 1) cout << 0 << "\n";
        else cout << "-1\n";
        return;
    }

    int counter = 0;
    while (!(a & 1 || b & 1 || c & 1)) {
        unsigned int temp1 = a, temp2 = b, temp3 = c;
        a = temp2 / 2 + temp3 / 2;
        b = temp1 / 2 + temp3 / 2;
        c = temp1 / 2 + temp2 / 2;
        counter++;
    }
    cout << counter << "\n";
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
