int solve(int n) {
    string st = to_string(n);
    int i = 0;
    for (i = st.size() - 2; i >= 0; i--) {
        if (st[i] < st[i + 1]) break;
    }

    if (i < 0) {
        reverse(st.begin(), st.end());
        return stoi(st);
    }

    int j = 0;
    for (j = st.size() - 1; j >= 0; j--) {
        if (st[j] > st[i]) break;
    }

    swap(st[i], st[j]);
    sort(st.begin() + i + 1, st.end());

    return stoi(st);
}