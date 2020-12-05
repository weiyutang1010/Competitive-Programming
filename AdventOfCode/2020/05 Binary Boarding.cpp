/*
* author: weiyutang
*         Wei Yu Tang 
*/
 
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"
 
using namespace std; 
 
const int MOD = 1e9 + 7;

int main() 
{
    //Add an empty line
    // ofstream foutput;
    // foutput.open ("input.txt",ios::app);
    // foutput<<"\n";
    // foutput.close();

    ifstream text("input.txt");
    string st;
    // Ans variable is used for part a to calculate max id
    // int ans = 0;
    vector<int> v(1024, 0);

    while (getline(cin , st)) {
        //process string and update ans
        if (st[0] != 0) {
            
            // Calculate row
            int row_pt1 = 0, row_pt2 = 127; 
            for (int i = 0; i < 7; i++) {
                int mid = row_pt1 + (row_pt2 - row_pt1) / 2;
                if (st[i] == 'F') {
                    row_pt2 = mid;
                } else {
                    row_pt1 = mid + 1;
                }
            }

            // Calculate col
            int col_pt1 = 0, col_pt2 = 7;
            for (int i = 7; i < 10; i++) {
                int mid = col_pt1 + (col_pt2 - col_pt1) / 2;
                if (st[i] == 'L') {
                    col_pt2 = mid;
                } else {
                    col_pt1 = mid + 1;
                }
            }

            // ans = max(ans, row_pt1 * 8 + col_pt1);
            v[row_pt1 * 8 + col_pt1] = 1;
        }
    }

    int idx = 0;
    for (int i = 0; i < 1024; i++) {
        if (v[i] == 1) {
            idx = i;
            break;
        }
    }

    for (int i = idx; idx < 1024; i++) {
        if (v[i] == 0) {
            cout << i << endl;
            break;
        }
    }

    // cout << ans << endl;

    text.close();
    return 0;
} 
