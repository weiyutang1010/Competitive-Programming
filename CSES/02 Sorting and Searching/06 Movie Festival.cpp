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
 
void solve() {
    int n;
    cin >> n;
    vector<ii> movie_time(n);
    for (int i = 0; i < n; i++) {
        cin >> movie_time[i].s;
        cin >> movie_time[i].f;
    }
 
    // Let movie's first value be end time
    // So we can sort movie in terms of how early they end
    sort(movie_time.begin(), movie_time.end());
 
    int end_time = movie_time[0].f;
    int movie_count = 1;
    for (int i = 1; i < n; i++) {
        if (movie_time[i].s >= end_time) {
            movie_count++;
            end_time = movie_time[i].f;
        }
    }
 
    cout << movie_count << endl;
 
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 