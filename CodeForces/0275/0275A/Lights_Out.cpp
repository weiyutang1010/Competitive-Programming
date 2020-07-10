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
    vector<vector<int> > v(3);
    vector<vector<int> > ans(3);
    int temp;

    //Getting input
    for (int i = 0; i < 3; i++) {
        v[i].resize(3);
        ans[i].resize(3);
        for (int j = 0; j < 3; j++) {
            cin >> temp;
            v[i][j] = temp;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //Finding the sum including adjacent
            int sum = v[i][j];
            if (i == 0) {
                sum += v[1][j];
            } else if (i == 1) {
                sum += v[0][j];
                sum += v[2][j];
            } else {
                sum += v[1][j];
            }

            if (j == 0) {
                sum += v[i][1];
            } else if (j == 1) {
                sum += v[i][0];
                sum += v[i][2];
            } else {
                sum += v[i][1];
            }

            //Check if the sum is odd or even.
            ans[i][j] = 1 - (sum & 1);
        }
    }

    //Printing answer
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i][j] << "";
        }
        cout << "\n";
    }
}