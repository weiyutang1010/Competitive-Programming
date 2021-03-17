void insert_space(vector<string>& ans, vector<string>& v, int count, int letters, int k) {
    // Join string in v with spaces and push to ans
    if (count > 1) {
        // More than 1 word

        // Calculate number of spaces require
        int space = k - letters;
        int single = space / (count - 1);
        int rem = space % (count - 1);

        string st = "";
        for (int k = 0; k < (int)v.size(); k++) {
            if (k == (int)v.size() - 1) {
                // don't add space for last word
                st += v[k];
            } else {
                string space(single + (rem > 0), ' ');
                st += v[k] + space;
                if (rem) rem--;
            }
        }
        ans.push_back(st);
    } else {
        // When there is only a single word
        string space(k - letters, ' ');
        string st = v[0] + space;
        ans.push_back(st);
    }
}

vector<string> solve(vector<string>& words, int k) {
    int n = words.size();
    vector<string> v;
    v.push_back(words[0]);
    vector<string> ans;

    // letters is current number of characters, count is number of words
    int letters = words[0].size(), count = 1;
    // i points to words, j points to v
    for (int i = 1, j = 0; i < n; i++) {
        // insert words into ans array if we have enought letters
        if (words[i].size() + count + letters - 1 >= k) {
            insert_space(ans, v, count, letters, k);

            // Reset vector and count
            v.clear();
            v.push_back(words[i]);
            letters = words[i].size();
            count = 1;
            j++;
        } else {
            v.push_back(words[i]);
            letters += words[i].size();
            count++;
        }
    }
    insert_space(ans, v, count, letters, k);

    return ans;
}