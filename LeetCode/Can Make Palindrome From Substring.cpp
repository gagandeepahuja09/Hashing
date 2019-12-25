class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        vector<vector<int>> freq(s.size(), vector<int>(26, 0));
        for(int i = 0; i < s.size(); i++) {
            if(i)
                freq[i] = freq[i - 1];
            freq[i][s[i] - 'a']++;
        }
        vector<bool> ret;
        for(auto v : q) {
            int l = v[0], r = v[1], k = v[2];
            int leftOvers = 0;
            if(l == 0) {
                for(int i = 0; i < 26; i++) {
                    leftOvers += ((freq[r][i] % 2) == 1);
                }
            }
            else {
                for(int i = 0; i < 26; i++) {
                    leftOvers += (((freq[r][i] - freq[l - 1][i]) % 2) == 1);
                }
            }
            ret.push_back(leftOvers - ((r - l) % 2 == 0) <= 2 * k);
        }
        return ret;
    }
};
