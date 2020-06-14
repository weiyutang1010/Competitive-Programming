#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int s;
    cin >> s;

    unordered_map<int, int> nums;

    nums[s] = 1;
    int n = s;
    int i = 1;
    while (true) {
        n = (n & 1) ? 3 * n + 1: n / 2;
        if (nums[n] == 0) {
            nums[n] = i;
        } else {
            //cout << "n: " << n << " nums: " << nums[n] << endl;
            cout << i+1 << endl;
            break;
        }
        i++;
    }
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
