// Return number of elements less than val
// If val is in v, set seen = true
int binary_search(vector<int>& v, int val, bool& seen) {
    int sz = v.size();
    int l = 0, r = v.size() - 1;

    if (v[l] >= val) {
        if (v[l] == val) seen = true;
        return 0;
    } else if (v[r] < val) {
        if (v[r] == val) seen = true;
        return sz;
    }

    int mid = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;

        // Check if val is in v
        if (v[mid] == val || (mid < sz && v[mid + 1] == val)) {
            seen = true;
        }

        if (v[mid] == val || v[mid] > val) {
            r = mid - 1;
        } else if (v[mid] < val) {
            if (mid < sz && v[mid + 1] >= val) {
                return mid + 1;
            }
            l = mid + 1;
        }
    }
    return l;
}

int solve(vector<int>& v1, vector<int>& v2) {
    int n = v1.size();
    int m = v2.size();
    int total_size = n + m;
    int median_idx = total_size / 2;

    if (n == 0) {
        return v2[median_idx];
    } else if (m == 0) {
        return v1[median_idx];
    }

    int left = min(v1[0], v2[0]), right = max(v1[n-1], v2[m-1]);
    int mid = 0;
    while (left <= right) {
        bool seen = false;
        mid = (left + right) / 2;

        // Find number of elements smaller than mid in v1 and v2
        int v1_elem = binary_search(v1, mid, seen);
        int v2_elem = binary_search(v2, mid, seen);

        int num = 0;
        for (int i = v1_elem; i < n; i++) {
            if (v1[i] == mid) {
                num++;
            } else {
                break;
            }
        }

        for (int i = v2_elem; i < m; i++) {
            if (v2[i] == mid) {
                num++;
            } else {
                break;
            }
        }

        // let num_elem rt be the last index of the value
        int num_elem_lt = v1_elem + v2_elem;
        int num_elem_rt = v1_elem + v2_elem + num - 1;

        if (median_idx >= num_elem_lt && median_idx <= num_elem_rt && seen) {
            return mid;
        } else if (num_elem_lt <= median_idx) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Median not found??
    return mid;
}