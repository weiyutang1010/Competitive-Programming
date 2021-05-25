vector<string> solve(vector<string>& sentence) {
    int n = sentence.size();
    // Reverse every character
    reverse(sentence.begin(), sentence.end());

    for (int l = 0, r = 0; r < n; r++) {
        if (r == n -1 || sentence[r + 1] == " ") {
            // Reverse every word
            reverse(sentence.begin() + l, sentence.begin() + r + 1);
            l = r + 2;
        }
    }
    return sentence;
}