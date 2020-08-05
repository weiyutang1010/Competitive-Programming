class WordDictionary {
public:
    map<int, vector<string>> words;
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        words[word.size() - 1].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int n = word.size();
        
        for (auto s: words[n - 1]) {
            bool match = true;
            if (s.size() == n) {
                for (int i = 0; i < n; i++) {
                    if (word[i] != '.' && word[i] != s[i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */