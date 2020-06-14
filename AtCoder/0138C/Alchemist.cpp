#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int &x: nums) {
        cin >> x;
    }

    sort(nums.begin(), nums.end());

    double temp = nums[0];
    for (int i = 1; i < n; i++) {
        temp = (nums[i] + temp) / 2; 
    }

    cout << temp << endl;
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
