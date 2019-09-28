class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> cb(26, 0);
        for(int i = 0; i < B.size(); i++) {
            vector<int> c(26, 0);
            for(auto ch : B[i]) {
                c[ch - 'a']++;    
            }
            for(int i = 0; i < 26; i++) {
                cb[i] = max(cb[i], c[i]);
            }
        }
        vector<string> ret;
        for(int i = 0; i < A.size(); i++) {
            vector<int> ca(26, 0);
            for(auto ch : A[i]) {
                ca[ch - 'a']++;    
            }
            int cnt = 0;
            for(int i = 0; i < 26; i++) {
                if(ca[i] >= cb[i])
                    cnt++;
            }
            if(cnt == 26)
                ret.push_back(A[i]);
        }
        return ret;
    }
};
