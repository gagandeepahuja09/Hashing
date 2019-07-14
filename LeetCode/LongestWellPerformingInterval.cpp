class Solution {
public:
    int longestWPI(vector<int>& h) {
        unordered_map<int, int> mp;
        int score = 0, ret = 0;
        for(int i = 0; i < h.size(); i++) {
            score += (h[i] > 8) ? 1 : -1;
            if(score > 0) {
                ret = i + 1;
            }
            else {
                if(mp.find(score) == mp.end())
                    mp[score] = i;
                if(mp.find(score - 1) != mp.end()) {
                    ret = max(ret, i - mp[score - 1]);
                }
            }
        }
        return ret;
    }
};
