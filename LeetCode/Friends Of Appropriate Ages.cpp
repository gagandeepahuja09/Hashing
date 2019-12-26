class Solution {
    bool request(int A, int B, vector<int>& age) {
        return !((B <= 0.5 * A + 7) || (B > A));
    }
    
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121, 0);
        for(int i = 0; i < ages.size(); i++)
            cnt[ages[i]]++;
        int ans = 0;
        for(int i = 1; i <= 120; i++) {
            for(int j = 1; j <= 120; j++) {
                if(cnt[i] && cnt[j] && request(i, j, ages)) {
                    ans += (cnt[i]) * (cnt[j] - (i == j));
                }
            }
        }
        return ans;
    }
};
