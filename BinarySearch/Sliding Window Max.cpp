#define f first
#define s second

struct comp {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

vector<int> solve(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;

    map<int, int, comp> mp;
    for (int i = 0; i < k; i++) {
        mp[nums[i]]++;
    }


    ans.push_back(mp.begin()->f);
    for (int l = 1, r = k; r < n; l++, r++) {
        // Remove old number
        mp[nums[l-1]]--;
        if (mp[nums[l-1]] == 0) {
            mp.erase(nums[l-1]);
        }

        // Insert new number
        mp[nums[r]]++;

        // Insert max value into ans
        ans.push_back(mp.begin()->f);
    }



    return ans;
}