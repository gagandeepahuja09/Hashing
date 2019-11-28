class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mp(60, 0);
        int ans = 0;
        for(int i = 0; i < time.size(); i++) {
            ans += mp[(60 - time[i] % 60) % 60];
            mp[time[i] % 60]++;
        }
        return ans;
    }
};
