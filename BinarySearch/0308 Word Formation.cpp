int solve(vector<string>& words, string letters) {
    int n = words.size();
    int m = letters.size();
    
    unordered_map<char, int> cnt;
    for (int i = 0; i < m; i++) {
        cnt[letters[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> temp = cnt;
        int char_found = 0;

        // Find how many matcheing characters
        for (char& c: words[i]) {
            if (temp[c] > 0) {
                char_found++;
                temp[c]--;
            }
            if (char_found == (int)words[i].size()) {
                ans = max(ans, char_found);
                break;
            }
        }

        
    }
    return ans;
}