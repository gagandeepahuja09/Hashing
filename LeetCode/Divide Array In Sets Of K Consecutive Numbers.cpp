class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        while(mp.size()) {
            int val = mp.begin() -> first;
            for(int i = val; i < val + k; i++) {
                if(mp[i] == 0)
                    return false;
                if(--mp[i] == 0)
                    mp.erase(i);
            }
        }
        return true;
    }
};
