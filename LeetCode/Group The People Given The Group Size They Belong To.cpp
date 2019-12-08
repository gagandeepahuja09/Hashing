class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < g.size(); i++) {
            mp[g[i]].push_back(i);
        }
        vector<vector<int>> ret;
        for(auto x : mp) {
            int u = x.first;
            vector<int> v = x.second;
            int i = 0;
            while(i < v.size()) {
                vector<int> t;
                int j;
                for(j = i; j < i + u && j < v.size(); j++) {
                    t.push_back(v[j]);
                }
                i = j;
                ret.push_back(t);
            }
        }
        return ret;
    }
};
