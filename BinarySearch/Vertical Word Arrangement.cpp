// O(n^2) solution
vector<string> solve(string s) {
    int n = s.size();
    vector<string> v;

    istringstream ss(s); // Split string by space (can also use strtok)
    string word;

    int row = 0;
    while (ss >> word) {
        for (int i = 0; i < word.size(); i++) {
			// check if idx is greater than array size
            if (i + 1 <= v.size()) {
				// check if needed to add space
                if (v[i].size() < row) {
                    for (int j = v[i].size(); j < row; j++) v[i] += ' ';
                }
                v[i] += word[i];
            } else {
                string st = "";
                for (int j = 0; j < row; j++) st += ' ';
                st += word[i];
                v.push_back(st);
            }
        }
        row++;
    }

    return v;
}
