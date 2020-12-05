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
    string st;

    int ans = 0;
    while (getline(cin , st)) {
        // Process input
        int range_low, range_high;
        char c;
        string pwd;

        string delimiter = " ";
        string st1 = st.substr(0, st.find(delimiter));
        
        //Get range
        range_low = stoi(st1.substr(0, st.find("-")));
        range_high = stoi(st1.substr(st.find("-") + 1));

        st.erase(0, st.find(delimiter) + 1); 

        c = st[0];
        pwd = st.substr(3);

        // validate password
        if (pwd[range_low - 1] == c && pwd[range_high - 1] == c) {
            ;
        } else if (pwd[range_low - 1] == c || pwd[range_high - 1] == c) {
            ans++;
        }
    }

    cout << ans << endl;

    text.close();
    return 0;
} 
