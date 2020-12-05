Report Repair/*
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
vector<string> eye_colors {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

bool process_input(string key, string value) {
    if (key == "byr") {
        int byr = stoi(value);
        if (byr >= 1920 && byr <= 2002) {
            return 1;
        }
    }

    if (key == "iyr") {
        int iyr = stoi(value);
        if (iyr >= 2010 && iyr <= 2020) {
            return 1;
        }
    }

    if (key == "eyr") {
        int eyr = stoi(value);
        if (eyr >= 2020 && eyr <= 2030) {
            return 1;
        }
    }

    if (key == "hgt") {
        if (value.size() < 3) {
            return 0;
        }

        int sz = value.size();

        string unit = value.substr(sz - 2);
        int hgt = stoi(value.substr(0, sz - 2));

        if (unit == "cm" && (hgt >= 150 && hgt <= 193)) {
            return 1;
        } else if (unit == "in" && (hgt >= 59 && hgt <= 76)) {
            return 1;
        }
    }

    if (key == "hcl") {
        if (value[0] == '#' && value.size() == 7) {
            for (int i = 1; i < (int)value.size(); i++) {
                char c = value[i];
                if ((c < 48 || c > 57) && (c < 97 || c > 102)) {
                    return 0;
                }
            }
            return 1;
        }
    }

    if (key == "ecl") {
        for (int i = 0; i < (int)eye_colors.size(); i++) {
            if (value == eye_colors[i]) {
                return 1;
            }
        }
    }

    if (key == "pid") {
        if ((int)value.size() == 9) {
            for (int i = 0; i < 9; i++) {
                char c = value[i];
                if (c < 48 || c > 57) {
                    return 0;
                }
            }
            return 1;
        }
    }

    return 0;
}

int main() 
{
    ifstream text("input.txt");
    map<string, int> m;

    string st;
    int ans = 0;
    while (getline(cin , st)) {
        // Check if all input is listed
        if (st[0] == 0) {
            int num_listed = 0;
            for (auto x: m) {
                if (x.f == "cid") continue;
                num_listed += x.s;
            }

            if (num_listed >= 7) {
                ans++;
            }
            m.clear();
            continue;
        }
        
        // Process string
        string delimiter = " ";
        
        while (st.size()) {
            int pos = st.find(delimiter);
            if (pos == -1) {
                string key = st.substr(0, 3);
                string value = st.substr(4);
                m[key] = process_input(key, value);
                break;
            }
            string token = st.substr(0, pos);
            string key = token.substr(0, 3);
            string value = token.substr(4);
            m[key] = process_input(key, value);
            st.erase(0, pos + 1);
        }
    }

    cout << ans << endl;

    text.close();
    return 0;
} 
