class Solution {
public:
    int flipgame(vector<int>& f, vector<int>& b) {
        unordered_set<int> s;
        int mn = INT_MAX;
        for(int i = 0; i < f.size(); i++) {
            if(f[i] == b[i])
                s.insert(f[i]);
        }
        for(int i = 0; i < f.size(); i++) {
            if(s.count(f[i]) == 0)
                mn = min(mn, f[i]);
            if(s.count(b[i]) == 0)
                mn = min(mn, b[i]);
        }
        return mn == INT_MAX ? 0 : mn;
    }
};
