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
    vector<int> v;
    int n;
    string st;

    v.push_back(0);

    while (cin >> n) {
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    int diff1 = 0, diff3 = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] - v[i - 1] == 1) {
            diff1++;
        } else if (v[i] - v[i - 1] == 3) {
            diff3++;
        }
    }

    cout << diff1 * diff3 << endl;

    text.close();
    return 0;
} 
