class Solution {
public:
    vector<int> xorQueries(vector<int>& A, vector<vector<int>>& q) {
        int n = A.size();
        vector<int> p(n);
        p[0] = A[0];
        vector<int> ret;
        for(int i = 1; i < A.size(); i++) {
            p[i] = A[i] ^ p[i - 1];
        }
        for(auto v : q) {
            int l = v[0], r = v[1];
            if(l == 0) {
                ret.push_back(p[r]);
            }
            else {
                ret.push_back(p[r] ^ p[l - 1]);
            }
        }
        return ret;
    }
};
