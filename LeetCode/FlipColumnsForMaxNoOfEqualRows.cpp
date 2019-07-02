class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> v = matrix[i];
            string curr = "";
            int top = v[0];
            for(int j = 1; j < v.size(); j++) {
                if(v[j] == top) {
                    curr += "1";
                }
                else
                    curr += "0";
            }
            mp[curr]++;
        }
        int mx = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            mx = max(mx, it -> second);
        }
        return mx;
    }
};
