/*
 * author: weiyutang
 */

#include <bits/stdc++.h>
using namespace std;

/* ===== BEGIN USER CODE ===== */

#define ll long long
#define ld long double
#define f first
#define s second
#define endl "\n"

const int MOD = 1e9 + 7;
const vector<vector<int>> dirs4 {{0,1}, {1,0}, {-1,0}, {0,-1}};
const vector<vector<int>> dirs8 {{0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};

// get the end index of a list or a number
int get_end(const string& st, int start, int end, bool is_list) {
    if (is_list) {
        int brac_count = 1;
        for (int i = start + 1; i < end; i++) {
            if (st.at(i) == '[') 
                brac_count++;
            if (st.at(i) == ']' && --brac_count == 0) 
                return i;
        }
    } else {
        for (int i = start; i < end; i++) {
            if (st.at(i) == ',') return i - 1;
        }
    }

    return end;
}

// return 1 if in right order, 0 in wrong order, -1 otherwise
int comp_helper(const string& s1, const string& s2, int start1, int end1, int start2, int end2) {
    // remove start and end brackets
    if (s1.at(start1) == '[' && s1.at(end1) == ']') {
        start1++, end1--;
    }

    if (s2.at(start2) == '[' && s2.at(end2) == ']') {
        start2++, end2--;
    }
    
    while (start1 <= end1 && start2 <= end2) {
        bool is_list1 = (s1.at(start1) == '['), is_list2 = (s2.at(start2) == '['); 
        int new_end1 = get_end(s1, start1, end1, is_list1), new_end2 = get_end(s2, start2, end2, is_list2);

        if (is_list1 || is_list2) {
            // if one value is a list, do a recursive call
            int res = comp_helper(s1, s2, start1, new_end1, start2, new_end2);
            if (res != -1)
                return res;
        } else {
            // otherwise, compare both values directly
            int a = stoi(s1.substr(start1, new_end1 - start1 + 1)), 
                b = stoi(s2.substr(start2, new_end2 - start2 + 1));
            if (a < b) {
                return 1;
            } else if (a > b) {
                return 0;
            }
        }

        start1 = new_end1 + 2, start2 = new_end2 + 2;
    }

    if (start1 > end1 && start2 > end2) {
        // both list ended
        return -1;
    } else if (start1 > end1) {
        return 1;
    } else {
        return 0;
    }
}

bool comp(const string& st1, const string& st2) {
    int n = st1.size(), m = st2.size();
    return comp_helper(st1, st2, 0, n-1, 0, m-1);
}

void part2(vector<string> inputs) {
	int ans = 0;
    
    // insert divisors
    inputs.push_back("[[2]]");
    inputs.push_back("[[6]]");

    int n = inputs.size();
    int idx1 = 0, idx2 = 0;
    sort(inputs.begin(), inputs.end(), comp);
    for (int i = 0; i < n; i++) {
        if (inputs[i] == "[[2]]") {
            idx1 = i + 1;
        } else if (inputs[i] == "[[6]]") {
            idx2 = i + 1;
        }
    }

    ans = idx1 * idx2;
	cout << "Part 2: " << ans << endl;
}

void part1(const vector<string>& inputs) {
	int n = inputs.size();
    int ans = 0;
   
    for (int i = 0; i < n; i += 2) {
        if (comp(inputs.at(i), inputs.at(i+1))) {
            ans += (i / 2) + 1;
        }
    }

    cout << "Part 1: " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;

    string st;
    vector<string> inputs;
    while (getline(cin, st)) {
        if (st.size() > 0)
            inputs.push_back(st);
    }


    while (t--) {
        part1(inputs);
		part2(inputs);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
