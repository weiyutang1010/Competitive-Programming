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

    while (getline(cin , st)) {
        v.push_back(st);
    }

    int line_num = 0;
    int sum = 0;
    map<int, bool> visited;
    while(!visited[line_num]) {
        visited[line_num] = 1;
        if (v[line_num].substr(0, 3) == "nop") {
            line_num++;
        } else if (v[line_num].substr(0, 3) == "acc") {
            sum += stoi(v[line_num].substr(4));
            line_num++;
        } else {
            line_num += stoi(v[line_num].substr(4));
        }    
    }

    cout << sum << endl;

    text.close();
    return 0;
} 
