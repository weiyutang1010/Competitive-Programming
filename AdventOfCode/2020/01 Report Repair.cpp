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
    int n = 200;
    int target = 2020;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 0; k < j; k++) {
                if (v[i] + v[j] + v[k] == 2020) {
                    cout << v[i] * v[j] * v[k] << endl;
                }
            }
        }
    }

    

    return 0;
} 
