#include <bits/stdc++.h> 
using namespace std; 
void solve(int); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
  
    int t = 1; 
    /*is Single Test case?*/ cin >> t; 
    solve(t); 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
void solve(int t) 
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num;
    
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> num;
            if (j % 3 == 0) {
                num1 += num;
            } else if (j % 3 == 1) {
                num2 += num;
            } else if (j % 3 == 2) {
                num3 += num;
            }
        }
    }
    if (num1 == 0 && num2 == 0 && num3 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
} 