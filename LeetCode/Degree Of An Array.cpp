class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp; 
        int mx = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
            mx = max(mx, (int)mp[nums[i]].size());
        }
        int ans = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]].size() == mx) {
                ans = min(ans, mp[nums[i]].back() - mp[nums[i]][0] + 1);
            }
        }
        return ans;
    }
};
