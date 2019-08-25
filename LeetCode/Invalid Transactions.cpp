class Solution {
public:
    vector<string> invalidTransactions(vector<string>& t) {
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < t.size(); i++) {
            vector<string> v;
            string s = "";
            for(int j = 0; j < t[i].size(); j++) {
                if(t[i][j] == ',') {
                    v.push_back(s);
                    s = "";
                }
                else
                    s += t[i][j];
            }
            v.push_back(s);
            bool f = false;
            for(auto it = mp.begin(); it != mp.end(); it++) {
                vector<string> c = it -> second;
                if(c[0] == v[0] && c[3] != v[3] 
                   && abs(stoi(c[1]) - stoi(v[1])) <= 60) {
                    if((it -> second).back() != "-1")
                        (it -> second).push_back("-1");
                    f = true;
                }
            }
            if(stoi(v[2]) > 1000 || f)
                v.push_back("-1");
            mp[t[i]] = v;
        }
        vector<string> ret;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if((it -> second).back() == "-1") {
                ret.push_back(it -> first);
            }
        }
        return ret;
    }
};
