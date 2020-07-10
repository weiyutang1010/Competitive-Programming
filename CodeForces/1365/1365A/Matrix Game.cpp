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

//Explanation: Each move is going to take away either 1 col or 1 row
//             We look for the maximum move for either entire row or col to be taken
//             We check if max move is odd or even which we decide the winner

void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> v (n);
 
    for (int i = 0; i < n; i++) {
        v[i].resize(m);
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            v[i][j] = temp;
        }
    }
 
    int count_row = n; //count number of valid rows
    for (int i = 0; i < n; i++) {
        bool found1 = false;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                found1 = true;
                break;
            }
        }
        if (found1) count_row--;
    }
 
 
    int count_col = m; //count number of valid columns
    for (int i = 0; i < m; i++) {
        bool found1 = false;
        for (int j = 0; j < n; j++) {
            if (v[j][i] == 1) {
                found1 = true;
                break;
            }
        }
        if (found1) count_col--;
    } 
 
    if (min(count_row, count_col) & 1) { //Check if min of valid rows and cols, is odd 
        cout << "Ashish\n";
    } else {
        cout << "Vivek\n";
    }
}