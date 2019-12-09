class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(k)
                sum %= k;
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
            else if(i - mp[sum] >= 2)
                return true;
        }
        return false;
    }
};
