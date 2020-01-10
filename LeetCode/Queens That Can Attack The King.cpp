class Solution {
public:
    // Instead of going for a hunt on king in each iteration, find queens to get killed 
    // the king in nearest vicinity
    // 8 * 8 Matrix => So limited to O(64)
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
        bool vis[8][8];
        memset(vis, false, sizeof vis);
        for(auto q : queens) {
            vis[q[0]][q[1]] = 1;
        }
        vector<vector<int>> ret;
        // Try all directions for king
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0)
                    continue;
                int x = k[0] + i, y = k[1] + j;
                // keep on going in this direction as long as valid x, y coords
                // or found a queen(and other queens get blocked by her so don't check)
                while(min(x, y) >= 0 && max(x, y) < 8) {
                    if(vis[x][y]) {
                        ret.push_back({ x, y });
                        break;
                    }
                    x += i; y += j;
                }
            }
        }
        return ret;
    }
};
