class VirtuallyCloneableStacks {
    vector<int> v;

    public:
    VirtuallyCloneableStacks() {
        v.push_back(0);
    }

    void copyPush(int i) {
        v.push_back(v[i] + 1);
    }

    void copyPop(int i) {
        v.push_back(v[i] - 1);
    }

    int size(int i) {
        return v[i];
    }
};