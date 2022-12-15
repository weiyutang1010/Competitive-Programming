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

void part2(const vector<pair<pair<int, int>, pair<int, int>>>& sensors) {
	int64_t ans = 0;
    const int lower = 0, upper = 4000000;
    const int64_t multiplier = 4000000;

    // for every y, find the interval that cannot contain a beacon
    vector<vector<pair<int, int>>> intervals (upper + 1);
    for (const auto& sensor: sensors) {
        pair<int, int> s_loc = sensor.f, b_loc = sensor.s;
        int manh_dist = abs(s_loc.f - b_loc.f) + abs(s_loc.s - b_loc.s);

        for (int y = max(lower, s_loc.s - manh_dist); y < min(upper, s_loc.s + manh_dist); y++) {
            int x_dist = manh_dist - abs(s_loc.s - y);
            intervals[y].push_back({s_loc.f - x_dist, s_loc.f + x_dist});
        }
    }

    // find two intervals that does not intersect in the same row,
    // the beacon is between the intervals
    bool found = false;
    for (int y = lower; y <= upper; y++) {
        sort(intervals[y].begin(), intervals[y].end());
        vector<pair<int, int>> merged_intervals {{0, 0}};

        for (int i = 0; i < intervals[y].size(); i++) {
            pair<int, int>& last_interval = merged_intervals.back();
            
            if (intervals[y][i].f <= last_interval.s) {
                last_interval.s = max(intervals[y][i].s, last_interval.s);
            } else {
                ans = (int64_t) (intervals[y][i].f - 1) * multiplier + y;
                found = true;
                break;
            }
        }

        if (found) break;
    }
    
	cout << "Part 2: " << ans << endl;
}

void part1(const vector<pair<pair<int, int>, pair<int, int>>>& sensors) {
    int64_t ans = 0;
    const int64_t target = 2000000;

    // find all intervals at y = target that cannot contain a beacon
    vector<pair<int, int>> intervals;
    for (const auto& sensor: sensors) {
        pair<int, int> s_loc = sensor.f, b_loc = sensor.s;

        int manhattan_dist = abs(s_loc.f - b_loc.f) + abs(s_loc.s - b_loc.s);
        int sensor_to_target = abs(s_loc.s - target);

        if (sensor_to_target > manhattan_dist)
            continue;

        int x_target = manhattan_dist - abs(s_loc.s - target);
        intervals.push_back({s_loc.f - x_target, s_loc.f + x_target});
    }

    if (intervals.size() == 0) {
        cout << "Part 1: " << ans << endl; 
        return;
    }

    // merge the intervals if intersected
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> merged_intervals {intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
        pair<int, int>& last_interval = merged_intervals.back();
        
        if (intervals[i].f <= last_interval.s) {
            last_interval.s = max(intervals[i].s, last_interval.s);
        } else {
            merged_intervals.push_back(intervals[i]);
        }
    }

    // find the total interval length
    for (auto& [start, end]: merged_intervals) {
        ans += end - start;
    }

    cout << "Part 1: " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;

    string st, token;
    // [sensor location, beacon loation]
    vector<pair<pair<int, int>, pair<int, int>>> sensors; 
    while (getline(cin, st)) {
        stringstream ss(st);
        sensors.push_back(pair<pair<int, int>, pair<int, int>> ());

        getline(ss, token, '=');
        getline(ss, token, ',');
        sensors.back().f.f = stoi(token);

        getline(ss, token, '=');
        getline(ss, token, ':');
        sensors.back().f.s = stoi(token);
        
        getline(ss, token, '=');
        getline(ss, token, ',');
        sensors.back().s.f = stoi(token);
        
        getline(ss, token, '=');
        getline(ss, token);
        sensors.back().s.s = stoi(token);
    }

    while (t--) {
        part1(sensors);
        part2(sensors);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
