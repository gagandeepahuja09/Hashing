class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string src) {
        string s;
        int m = src.size();
        sort(p.begin(), p.end());
        vector<vector<string>> ret;
        int n = p.size();
        vector<int> cnt;
        for(string t : p) {
            cout << t << endl;
            int i = 0, c = 0;
            for(i = 0; i < src.size() && i < t.size(); i++) {
                if(src[i] == t[i]) {
                    c++;
                }
                else
                    break;
            }
            cnt.push_back(i);
        }
        for(int i = 0; i < m; i++) {
            vector<string> v;
            for(int j = 0; j < n; j++) {
                if(cnt[j] > i && v.size() < 3) {
                    v.push_back(p[j]);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};
