class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        map<int, int> mp1;
        map<int, int> mp2;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 1) {
                    mp1[i]++;
                    mp2[j]++;
                    cnt++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 1 && mp1[i] == 1 && mp2[j] == 1) {
                    cnt--;
                }
            }
        }
        return cnt;
    }
};
