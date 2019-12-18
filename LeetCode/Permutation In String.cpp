class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26, 0);
        if(s1.size() > s2.size())
            return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        int n = s1.size(), m = s2.size();
        for(int i = 0; i < n; i++) {
            mp1[s1[i]]++;
        }
        for(int i = 0; i < n; i++) {
            mp2[s2[i]]++;
        }
        if(mp1 == mp2) {
            return true;
        }
        for(int i = n; i < m; i++) {
            mp2[s2[i]]++;
            if(--mp2[s2[i - n]] == 0)
                mp2.erase(s2[i - n]);
            if(mp1 == mp2)
                return true;
        }
        return false;
    }
};
