#include <bits/stdc++.h>
#include <cmath>

#define ulli unsigned long long int
#define ll long long
#define ld long double

using namespace std; 
void solve(); 
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
    // cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 

void solve() 
{ 
	vector<vector<int> > card;
    int temp;

    card.resize(3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> temp;
            card[i].push_back(temp);
        }
    }

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> temp;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (temp == card[j][k]) {
                    card[j][k] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 ) {
            cout << "Yes\n";
            return;
        }

        if (card[0][i] == 0 && card[1][i] == 0 && card[2][i] == 0 ) {
            cout << "Yes\n";
            return;
        }

        if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 ) {
            cout << "Yes\n";
            return;
        }

        if (card[0][2] == 0 && card[1][1] == 0 && card[2][0] == 0 ) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}
