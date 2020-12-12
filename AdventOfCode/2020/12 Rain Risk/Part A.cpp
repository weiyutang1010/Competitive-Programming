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

    ii dir {1, 0};
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

            if (dir.f) {
                if ((x[0] == 'L' && dir.f == 1) || (x[0] == 'R' && dir.f == -1)) {
                    dir.s = 1;
                } else {
                    dir.s = -1;
                }
                if (val == 270) dir.s *= -1;
                dir.f = 0;
            } else {
                if ((x[0] == 'R' && dir.s == 1) || (x[0] == 'L' && dir.s == -1)) {
                    dir.f = 1;
                } else {
                    dir.f = -1;
                }
                if (val == 270) dir.f *= -1;
                dir.s = 0;
            }
            continue;
        }

        // Update position
        if ((x[0] == 'N') || (x[0] == 'F' && dir.f == 0 && dir.s == 1)) {
            ypos += val;
        } else if ((x[0] == 'E') || (x[0] == 'F' && dir.f == 1 && dir.s == 0)) {
            xpos += val;
        } else if ((x[0] == 'S') || (x[0] == 'F' && dir.f == 0 && dir.s == -1))  {
            ypos -= val;
        } else if ((x[0] == 'W') || (x[0] == 'F' && dir.f == -1 && dir.s == 0)) {
            xpos -= val;
        }
    }


    cout << abs(xpos) + abs(ypos) << endl;

    text.close();
    return 0;
} 
