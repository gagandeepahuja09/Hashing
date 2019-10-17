class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_map<string, int> mp;
        for(int i = 0; i < A.size(); i++) {
            string s1, s2;
            for(int j = 0; j < A[i].size(); j++) {
                if(j % 2) {
                    s1 += A[i][j];
                }
                else
                    s2 += A[i][j];
            }
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            // cout << s1 + '_' + s2 << endl;
            mp[s1 + '_' + s2]++;
        }
        return mp.size();
    }
};
