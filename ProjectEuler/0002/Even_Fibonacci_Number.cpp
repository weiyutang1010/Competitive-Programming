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
  
//#ifndef ONLINE_JUDGE 
//    freopen("input.txt", "r", stdin); 
//    freopen("error.txt", "w", stderr); 
//    freopen("output.txt", "w", stdout); 
//#endif 
  
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
void solve() {
    vector<int> fib {1, 2}; //vector to store all fibonacci sequence
    ll ans = 2; //add answer if only new summation is even

    int new_sum = 0;
    while(new_sum <= 4000000) {
        new_sum = fib[fib.size() - 2] + fib[fib.size() - 1]; //access last and second last element
        if (!(new_sum & 1)) { //check if new number is even
            ans+= new_sum;
        }
        fib.push_back(new_sum); //appending new number to vec
    }

    cout << ans << "\n";
}