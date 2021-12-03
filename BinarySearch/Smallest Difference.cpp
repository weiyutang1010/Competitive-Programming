struct Num {
    int val;
    int i;
    int j;
};

// compare function for min_heap
struct compare_num {
    bool operator()(Num const& n1, Num const& n2) {
        return n1.val > n2.val;
    }
};

int solve(vector<vector<int>>& lists) {
    int n = lists.size();
    if (n == 0) return 0;
    int m = lists[0].size();

    int max_n = INT_MIN;
    priority_queue<Num, vector<Num>, compare_num> pq;

	// sort each sublists and store min value in pq
	// keep track of max_n of all nums stored in pq
    for (int i = 0; i < n; i++) {
        sort(lists[i].begin(), lists[i].end());
        struct Num temp;
        temp.val = lists[i][0];
        temp.i = i;
        temp.j = 0;
        pq.push(temp);
        max_n = max(max_n, lists[i][0]);
    }

	// compute max_n - min_n
	// then pop min_n and push next element on the list
    int ans = INT_MAX;
    while (true) {
        auto [val, i, j] = pq.top();
        pq.pop();
        ans = min(ans, max_n - val);

        if (j+1 >= lists[i].size()) {
            break;
        }
        
        pq.push({lists[i][j+1], i, j+1});
        max_n = max(max_n, lists[i][j+1]);
        
    }
    return ans;
}
