class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int count[100] = {};
        int ans = 0;
        for(int i = 0; i < d.size(); i++) {
            int num = min(d[i][0], d[i][1]) * 10 + max(d[i][0], d[i][1]);
            ans += count[num];
            count[num]++;
        }
        return ans;
    }
};
