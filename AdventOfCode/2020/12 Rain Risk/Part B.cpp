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
    ifstream text("input.txt");
    vector<string> v;
    string st;

    while (cin >> st) {
        v.push_back(st);
    }

    ii dir {10, 1};
    int xpos = 0, ypos = 0;
    for (string& x: v) {
        int val = stoi(x.substr(1));

        // Change direction
        if (x[0] == 'L' || x[0] == 'R') {
            if (val == 180) {
                dir.f *= -1;
                dir.s *= -1;
                continue;
            } 

            int temp;
            if ((x[0] == 'L' && val == 90) || (x[0] == 'R' && val == 270)) {
                dir.s *= -1;
            } else if ((x[0] == 'R' && val == 90) || (x[0] == 'L' && val == 270)) {
                dir.f *= -1;
            }
            temp = dir.f;
            dir.f = dir.s;
            dir.s = temp;
            continue;
        }


        // More change direction
        if (x[0] == 'N') {
            dir.s += val;
        } else if (x[0] == 'E') {
            dir.f += val;
        } else if (x[0] == 'S')  {
            dir.s -= val;
        } else if (x[0] == 'W') {
            dir.f -= val;
        }

        // Update position
        if (x[0] == 'F') {
            xpos += dir.f * val;
            ypos += dir.s * val;
        }
    }

    // Let there be no more bug please ; - ;
    cout << abs(xpos) + abs(ypos) << endl;

    text.close();
    return 0;
} 
