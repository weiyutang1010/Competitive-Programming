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
    vector<int> j_or_n;
    while(!visited[line_num]) {
        visited[line_num] = 1;

        if (v[line_num].substr(0, 3) == "nop") {
            j_or_n.push_back(line_num);
            line_num++;
        } else if (v[line_num].substr(0, 3) == "acc") {
            sum += stoi(v[line_num].substr(4));
            line_num++;
        } else {
            j_or_n.push_back(line_num);
            line_num += stoi(v[line_num].substr(4));
        }    
    }

    for (int i = 0; i < (int)j_or_n.size(); i++) {
        if (v[j_or_n[i]].substr(0, 3) == "jmp") {
            v[j_or_n[i]] = "nop" + v[j_or_n[i]].substr(3);
        }
        else if (v[j_or_n[i]].substr(0, 3) == "nop") {
            v[j_or_n[i]] = "jmp" + v[j_or_n[i]].substr(3);
        }

        line_num = 0;
        sum = 0;
        visited.clear();

        while(!visited[line_num]) {
            if (line_num >= (int)v.size()) {
                cout << sum << endl;
                return 0;
            }

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
        
        if (v[j_or_n[i]].substr(0, 3) == "jmp") {
            v[j_or_n[i]] = "nop" + v[j_or_n[i]].substr(3);
        }
        else if (v[j_or_n[i]].substr(0, 3) == "nop") {
            v[j_or_n[i]] = "jmp" + v[j_or_n[i]].substr(3);
        }
    }


    text.close();
    return 0;
} 
