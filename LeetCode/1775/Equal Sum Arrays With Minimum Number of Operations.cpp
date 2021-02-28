#define f first
#define s second

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if (m * 6 < n || n * 6 < m) {
            return -1;
        }
        
        int sum1 = 0, sum2 = 0, diff;
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
        }
        for (int i = 0; i < m; i++) {
            sum2 += nums2[i];
        }
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int pt1_s = 0, pt1_l = n - 1;
        int pt2_s = 0, pt2_l = m - 1;

        int ans = 0;
        if (sum1 < sum2) {
            while (sum1 < sum2) {
                if (sum1 < m) {
                    sum1 += 6 - nums1[pt1_s];
                    pt1_s++;
                } else {
                    if (pt1_s == n || nums2[pt2_l] - 1 > 6 - nums1[pt1_s]) {
                        sum2 -= nums2[pt2_l] - 1;
                        pt2_l--;
                    } else {
                        sum1 += 6 - nums1[pt1_s];
                        pt1_s++;
                    }
                }
                ans++;
            }   
        } else if (sum2 < sum1) {
            while (sum2 < sum1) {
                if (sum2 < n) {
                    sum2 += 6 - nums2[pt2_s];
                    pt2_s++;
                } else {
                    if (pt2_s == m || nums1[pt1_l] - 1 > 6 - nums2[pt2_s]) {
                        sum1 -= nums1[pt1_l] - 1;
                        pt1_l--;
                    } else {
                        sum2 += 6 - nums2[pt2_s];
                        pt2_s++;
                    }
                }
                ans++;
            } 
        }
        
        
        return ans;
    }
};