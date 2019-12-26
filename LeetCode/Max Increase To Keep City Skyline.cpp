class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), ans = 0;
        vector<int> mxr(m, INT_MIN);
        vector<int> mxc(n, INT_MIN);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans -= g[i][j];
                mxr[i] = max(mxr[i], g[i][j]);
            }
        }
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                mxc[j] = max(mxc[j], g[i][j]);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += min(mxr[i], mxc[j]);
            }
        }
        return ans;
    }
};
