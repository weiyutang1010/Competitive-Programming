bool solve(vector<string>& moves, int x, int y) {
    map<string, pair<int, int>> dir = {{"NORTH", {0, 1}}, {"SOUTH", {0, -1}}, {"WEST", {-1, 0}}, {"EAST", {1, 0}}};
    int n = moves.size();
    int curr_x = 0, curr_y = 0;
    for (int i = 0; i < n; i++) {
        curr_x += dir[moves[i]].first;
        curr_y += dir[moves[i]].second;
    }

    return curr_x == x && curr_y == y;
}