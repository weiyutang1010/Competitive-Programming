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

int64_t mulInv(int64_t a, int64_t b) {
    int b0 = b;
    int x0 = 0;
    int x1 = 1;

    if (b == 1) return 1;

    while (a > 1) {
        int q = a/b;
        int amb = a % b;
        a = b;
        b = amb;

        int xqx = x1 - q * x0;
        x1 = x0;
        x0 = xqx;
    }

    if (x1 < 0) {
        x1 += b0;
    }

    return x1;
}

int64_t chinese_remainder(vector<int> n, vector<int> a) {
    int64_t prod = 1;
    for (int& x: n) prod *= x;

    int64_t sm = 0;
    for (int i = 0; i < (int)n.size(); i++) {
        int64_t p = prod / n[i];
        sm += a[i] * mulInv(p, n[i]) * p;
    }

    return sm % prod;
}

int main() 
{
    ifstream text("input.txt");
    int n;
    string st;
    cin >> n;
    cin >> st;
    vector<int> bus;
    vector<int> bus_time;
    int t = 0;
    while (st.size() >= 0) {
        int pos = st.find(',');
        if (st[0] == 'x') {
            st.erase(0, 2);
            t++;
            continue;
        }
        if (pos == -1) {
            bus.push_back(stoi(st.substr(0)));
            bus_time.push_back(t);
            break;
        }
        bus.push_back(stoi(st.substr(0,pos)));
        bus_time.push_back(t);
        st.erase(0,pos + 1);
        t++;
    }

    for (int i = 0 ; i < (int)bus.size(); i++) {
        bus_time[i] = bus[i] - bus_time[i];
    }

    cout << chinese_remainder(bus, bus_time) << endl;


    text.close();
    return 0;
} 
