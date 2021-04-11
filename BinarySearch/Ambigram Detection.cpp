class dsu {
public:
    vector<int> link;
    vector<int> size;
    int num_components;

    dsu(int N) {
        num_components = N;
        size.assign(N, 1);
        link.assign(N, 0);
        for (int i = 0; i < N; i++) {
            link[i] = i;
        }
        return;
    }

    int find(int a) {
        while (a != link[a]) {
            a = link[a];
        }
        return a;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (size[a] > size[b]) {
            swap(a, b);
        }
        link[a] = b;
        size[b] += size[a];
        num_components--;
        return true;
    }
};

bool solve(string s, vector<vector<string>>& pairs) {
    int n = s.size(), p = pairs.size();
    dsu d(26);

    // Use dsu to combine letters together
    for (int i = 0; i < p; i++) {
        d.unite(pairs[i][0][0] - 'a', pairs[i][1][0] - 'a');
    }

    for (int l = 0, r = n - 1; l < r; l++, r--) {
        if (s[l] != s[r] && d.find(s[l] - 'a') != d.find(s[r] - 'a')) {
            return false;
        }
    }

    return true;
}