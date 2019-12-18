class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        for(vector<int> v : wall) {
            int sum = 0;
            for(int i = 0; i < v.size(); i++) {
                sum += v[i];
                if(i < v.size() - 1)
                    mp[sum]++;
            }
        }
        int ans = 0, mx = 0;
        for(auto it : mp) {
            if(it.second > mx) {
                mx = it.second;
                // ans = it.first;
            }
        }
        return wall.size() - mx;
    }
};
