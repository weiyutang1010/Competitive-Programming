using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> hashmap;
        for (auto x: A) {
            hashmap[x]++;
            if (hashmap[x] > 1) {
                return x;
            }
        }
       return ans;
        return 0;
    }
};