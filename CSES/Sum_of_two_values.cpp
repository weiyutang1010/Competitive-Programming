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
    int n;
    int x; //target value
    map<int, int> m; //hashmap to store value and index
    int temp;

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        int num = x - temp; //The value we are looking for is target - current number 
        if (m.find(num) != m.end()) { //Check if that number already exist in hashmap
            cout << m[num]+1 << " " << i+1 << "\n"; //if yes, print that index and current index
            return;
        } else {
            m[temp] = i; //If not found store the value in the hashmap with its index
        }
    }

    cout << "IMPOSSIBLE\n";
}
