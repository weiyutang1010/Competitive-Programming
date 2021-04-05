bool comp(const string& a, const string& b) {
    int A = stoi(a);
    int B = stoi(b);

    int n = a.size();
    int m = b.size();

    int temp = B;
    B *= pow(10, n);
    B += A;

    A *= pow(10, m);
    A += temp;

    return B < A;
}

string solve(vector<int>& nums) {
    int n = nums.size();
    vector<string> str(n);
    
    for (int i = 0; i < n; i++) {
        str[i] = to_string(nums[i]);
    }

    sort(str.begin(), str.end(), comp);
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += str[i];
    }

    return ans;
}