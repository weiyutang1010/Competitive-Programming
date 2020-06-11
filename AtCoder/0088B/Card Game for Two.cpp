#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 

void solve() {
    int n;
    cin >> n;

    vector<int> v;
    make_heap(v.begin(), v.end());

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        push_heap(v.begin(), v.end());
    }

    int a_points = 0;
    int b_points = 0;
    for (int i = 0; i < n; i++) {
        (i & 1) ? b_points += v.front() : a_points += v.front();
        pop_heap(v.begin(), v.end());
        v.pop_back();
    }

    cout << a_points - b_points << "\n";
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
