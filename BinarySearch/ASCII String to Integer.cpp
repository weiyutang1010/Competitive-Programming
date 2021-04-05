int solve(string s) {
    int ans = 0;
    string num = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] >'9') {
            if (num.size() > 0) {
                ans += stoi(num);
                num.clear();    
            }
        } else {
            num += s[i];
        }
    }
    if (num.size() > 0) ans += stoi(num);
    return ans;
}