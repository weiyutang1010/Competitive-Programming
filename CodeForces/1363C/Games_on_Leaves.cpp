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
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 

//Explanation: the player will keep picking nodes until the target node is left connected with two other nodes.
//             because if a player pick either of those node, the target node becomes a leaf. 
//             So whoever has to pick one of them lose. 
//             So if it is even number of total nodes then Ayush wins and if odd number then Ashish wins. 
//             Except for the case when the target node is already a leaf which means Ayush will win.

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> v;
    int temp;
    for (int i = 0; i < (n-1) * 2; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    //cout << count(v.begin(), v.end(), x) << endl;
    if (count(v.begin(), v.end(), x) > 1) {
        if (n & 1) {
            cout << "Ashish\n";
        } else {
            cout << "Ayush\n";
        }
    } else {
        cout << "Ayush\n";
    }
}