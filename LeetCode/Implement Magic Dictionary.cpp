class MagicDictionary {
public:
    unordered_set<string> words;
    /** Initialize your data structure here. */
    MagicDictionary() { 
        words.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string s : dict) {
            words.insert(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            for(int j = 0; j < 26; j++) {
                if(j + 'a' == c)
                    continue;
                word[i] = j + 'a';
                if(words.count(word)) {
                    return true;
                }
            }
            word[i] = c;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
