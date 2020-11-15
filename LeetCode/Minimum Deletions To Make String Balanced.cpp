class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), maxLength = 0, ca = 0, cb = 0, ans = 0;
        vector<int> suffixB(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == 'b')
                cb++;
            suffixB[i] = cb;
        }
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                ca++;
                ans = max(ans, ca);
            }
            else {
                ans = max(ans, ca + suffixB[i]);
            }
        }
        return n - ans;
    }
};
