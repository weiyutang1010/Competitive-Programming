#define f first
#define s second

class Solution {
public:
    void dfs(int& ans, int& cost, unordered_map<int, int> cnt, int curr, int& target) {
        if (abs(curr - target) < cost) {
            cost = abs(curr - target);
            ans = curr;
        } else if (abs(curr - target) == cost && curr < ans) {
            ans = curr;
        }
        
        if (curr >= target) {
            return;
        }
        
        for (auto& x: cnt) {
            if (x.s) {
                cnt[x.f]--;
                dfs(ans, cost, cnt, curr + x.f, target);
                cnt[x.f]++;
            }
        }
        return;
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size();
        int m = toppingCosts.size();
        
        unordered_map<int, int> cnt;
        for (int i = 0; i < m; i++) {
            cnt[toppingCosts[i]] += 2;
        }
        
        int ans = 0, cost = INT_MAX;
        for (int i = 0; i < n; i++) {
            dfs(ans, cost, cnt, baseCosts[i], target);
        }
        return ans;
    }
};