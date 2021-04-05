unordered_map<int, int> nodes; // DSU array
unordered_map<int, int> sizes; // Keep track of element size

struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }
};

int find_set(int v) {
    if (v == nodes[v]) {
        return v;
    }
    return nodes[v] = find_set(nodes[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (sizes[a] < sizes[b]) {
            swap(a, b);
        }
        nodes[b] = a;
        sizes[a] += sizes[b];
    }
}

void init_sets(vector<vector<int>>& edges) {
    nodes.clear(); sizes.clear();
    for (int i = 0; i < edges.size(); i++) {
        if (!nodes[edges[i][0]]) {
            nodes[edges[i][0]] = edges[i][0];
            sizes[edges[i][0]] = 1;
        }

        if (!nodes[edges[i][1]]) {
            nodes[edges[i][1]] = edges[i][1];
            sizes[edges[i][1]] = 1;
        }
    }
}

int kruskal(vector<vector<int>>& edges, int a, int b, int& target_idx, int edgeCount = 0, int weight = 0) {
    int i = 0;
    while (i < edges.size() && edgeCount < edges.size() - 1) {
        int x = find_set(edges[i][0]), y = find_set(edges[i][1]);

        if (x != y) {
            union_sets(x, y);
            weight += edges[i][2];
            edgeCount++;
        }

        if ((edges[i][0] == a && edges[i][1] == b) ||
            (edges[i][0] == b && edges[i][1] == a)) {
            target_idx = i;
        }

        i++;
    }
    return weight;
}

bool solve(vector<vector<int>>& edges, int a, int b) {
    sort(edges.begin(), edges.end(), comp());

    int target_idx = -1;
    init_sets(edges);
    int w1 = kruskal(edges, a, b, target_idx);

    if (target_idx == -1) target_idx = edges.size() - 1;

    init_sets(edges);
    union_sets(a, b);
    int w2 = kruskal(edges, a, b, target_idx, 1, edges[target_idx][2]);

    return w1 == w2;
}