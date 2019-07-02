class Solution {
public:
    bool isvow(char x) {
        return ((x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x == 'u') ||
            (x == 'A') || (x == 'E') || (x == 'I') || (x == 'O') || (x == 'U'));
    }
    
    string cap(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(isupper(s[i])) {
                s[i] = tolower(s[i]);
            }
        }
        return s;
    }
    
    string vow(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(isupper(s[i])) {
                s[i] = tolower(s[i]);
            }
            if(isvow(s[i])) {
                s[i] = '!';
            }
        }
        return s;
    }
    
    vector<string> spellchecker(vector<string>& w, vector<string>& q) {
        unordered_map<string, string> mp;
        unordered_set<string> st;
        unordered_map<string, string> mp2;
        for(int i = 0; i < w.size(); i++) {
            st.insert(w[i]);
            string n = cap(w[i]);
            if(mp.find(n) == mp.end()) {
                mp[n] = w[i];
            }
            n = vow(w[i]);
            if(mp2.find(n) == mp2.end()) {
                mp2[n] = w[i];
            }
        }
        vector<string> ret;
        for(int i = 0; i < q.size(); i++) {
            string n = cap(q[i]);
            if(st.find(q[i]) != st.end()) {
                ret.push_back(q[i]);
            }
            else if(mp.find(n) != mp.end()) {
                ret.push_back(mp[n]);
            }
            else {
                n = vow(q[i]);
                if(mp2.find(n) != mp2.end()) {
                    ret.push_back(mp2[n]);
                }
                else {
                    ret.push_back("");
                }
            }
        }
        return ret;    
    }
};
