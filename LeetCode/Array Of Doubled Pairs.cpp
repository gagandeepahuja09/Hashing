class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int c1 = 0, c2 = 0;
        unordered_map<int, int> mp;
        for(auto it : A)
            mp[it]++;
        sort(A.begin(), A.end());
        for(auto it : A) {
            if(!mp[it])
                continue;
            int val = it < 0 ? it / 2 : it * 2;
            if(!mp[val])
                return false;
            else
                mp[val]--;
            mp[it]--;
        }
        return true;
    }
};
