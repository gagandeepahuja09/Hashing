class Solution {
public:
    int countPairs(vector<int>& del) {
        map<long, long> mp;
        sort(del.begin(), del.end());
        for (int i = 0; i < del.size(); i++) {
            mp[(long)del[i]]++;
        }
        int maxVal = pow(2, 21);
        long MOD = 1e9 + 7;
        long ans = 0;
        for (auto it : mp) {
            long val = it.first, count = it.second;
            if (val > del.back()) {
                break;
            }
            if (mp[val]) {
                for (int k = 1; k <= maxVal; k *= 2) {
//                     if (mp[k - val]) will insert in map, if it doesn't exist
                    if (mp.count(k - val) && k - val >= val) {
                        if (k - val != val)
                            ans += (mp[val] % MOD * mp[k - val] % MOD);
                        else 
                            ans += (mp[val] * (mp[k - val] - 1)) / 2;
                    }
                    ans %= MOD;
                }
            }
        }
        return ans;
    }
};
