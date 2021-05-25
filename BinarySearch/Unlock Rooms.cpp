bool solve(vector<vector<int>>& rooms) {
    int n = rooms.size();
    set<int> visited;

    // Use dfs to visit room that we have access to
    function<void(int)> dfs = [&] (int curr) {
        if ((int)visited.size() == n) return;
        visited.insert(curr);
        for (int& x: rooms[curr]) {
            // Make sure we are not visiting room that we have visited
            if (visited.find(x) == visited.end())
                dfs(x);
        }
        return;
    };
    dfs(0);

    // If we can access all rooms, then we have all keys
    return (int)visited.size() == n;
}