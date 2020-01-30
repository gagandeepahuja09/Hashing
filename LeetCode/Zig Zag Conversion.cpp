class Solution {
public:
    string convert(string s, int n) {
        vector<string> v(n);
        int curr = 0, r = 0;
        for(int i = 0; i < s.size(); i++) {
            v[curr] += s[i];
            if(r == 0) {
                curr = (curr + 1) % n;
            }
            else {
                curr--;    
            }
            if(curr == n - 1) {
                r = 1;
            }
            if(curr == 0) {
                r = 0;
            }
        }
        string ret;
        for(int i = 0; i < v.size(); i++) {
            ret += v[i];
        }
        return ret;
    }
};
