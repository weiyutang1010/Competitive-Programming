string convert_to_ip(const vector<string>& curr) {
    string st = curr[0] + '.' + curr[1] + '.' + curr[2] + '.' + curr[3];
    return st;
}

bool in_range(const vector<string>& curr) {
    for (int i = 0; i < 4; i++) {
        int val = stoi(curr[i]);
        if (val < 0 || val > 255) {
            return false;
        }
    }
    return true;
}

bool has_leading_zero(const vector<string>& curr) {
    for (int i = 0; i < 4; i++) {
        if (curr[i].size() > 1 && curr[i][0] == '0') {
            return true;
        }
    }
    return false;
}

void backtrack(vector<string>& ans, vector<string> curr, string ip, int len, int idx) {
    if (idx > len) return;

    if (curr.size() == 4 && idx == len) {
        // check if any number has leading 0
        // check if all numbers are in range
        // if both yes then add to ans
        if (!has_leading_zero(curr) && in_range(curr)) {
            ans.push_back(convert_to_ip(curr));
        } else {
            return;
        }
    }
    
    if ((double)(len - idx) / (4.0 - curr.size()) > 3) {
        return;
    }

    for (int i = 1; i <= 3; i++) {
        curr.push_back(ip.substr(idx, i));
        backtrack(ans, curr, ip, len, idx + i);
        curr.pop_back();
    }

    return;
}

vector<string> solve(string ip) {
    vector<string> ans;
    vector<string> curr;
 
    // Find all possible way to split ip into 4 values
    backtrack(ans, curr, ip, ip.size(), 0);
    return ans;
}