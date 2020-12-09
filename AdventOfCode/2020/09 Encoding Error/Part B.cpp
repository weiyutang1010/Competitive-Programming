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

bool found_sum(vector<int64_t>& v, int p_low, int p_high, int64_t target) {
    map<int64_t, int> m;
    m[v[p_low]] = 1;
    for (int i = p_low + 1; i < p_high; i++) {
        if (m[target - v[i]]) {
            return true;
        }
        m[v[i]] = 1;
    }


    return false;
}

int main() 
{
    ifstream text("input.txt");
    vector<int64_t> v;
    int64_t val = 0;
    string st;

    while (cin >> val) {
        v.push_back(val);
    }

    // Check all previous 25 nums if any doesn't sum to current value
    int64_t ans = 0;
    for (int i = 25; i < (int)v.size(); i++) {
        if (!found_sum(v, i - 25, i, v[i])) {
            ans = v[i];
            break;
        }
    }


    // Use sliding window to find the range that sums to ans
    int lt = 0, rt = 1;
    int64_t sum = v[lt] + v[rt];
    while(sum != ans) {
        if (sum > ans) {
            sum -= v[lt];
            lt++;
        }

        if (sum < ans) {
            rt++;
            sum += v[rt];
        }
    }

    // Find smallest and largest value in the array
    int64_t small = v[lt], big = v[lt];
    for (int i = lt; i <= rt; i++) {
        small = min(small, v[i]);
        big = max(big, v[i]);
    }

    cout << small + big << endl;


    text.close();
    return 0;
} 
