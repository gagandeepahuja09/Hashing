class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto it : mp) {
            buckets[it.second].push_back(it.first);
        }
        vector<int> ret;
        for(int i = nums.size(); i >= 0 ; i--) {
            for(int j = 0; j < buckets[i].size(); j++) {
                ret.push_back(buckets[i][j]);
                if(ret.size() == k)
                    return ret;
            }
        }
        return ret;    
    }
};
