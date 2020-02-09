class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cs(26, 0), ct(26, 0);
        for(char c : s)
            cs[c - 'a']++;
        for(char c : t)
            ct[c - 'a']++;
        int ans = 0;
        for(int i = 0; i < 26; i++) 
            ans += abs(cs[i] - ct[i]);
        return ans / 2;
    }
};
