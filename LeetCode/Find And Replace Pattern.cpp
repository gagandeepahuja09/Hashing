class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        words.push_back(pattern);
        string t;
        bool flag = false;
        unordered_map<string, vector<string>> combs;
        for(string s : words) {
            string s2;
            unordered_map<char, char> mp;
            char curr = '1';
            for(int i = 0; i < s.size(); i++) {
                if(mp.find(s[i]) == mp.end()) {
                    curr++;
                    s2 += curr;
                    mp[s[i]] = curr;
                }
                else {
                    s2 += mp[s[i]];
                }
            }
            // cout << s2 << endl;
            combs[s2].push_back(s);
            if(s == pattern && !flag) {
                flag = true;
                t = s2;
                combs[s2].pop_back();
            }
        }
        return combs[t];
    }
};
