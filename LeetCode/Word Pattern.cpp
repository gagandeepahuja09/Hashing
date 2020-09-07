class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, string> mpp, mps;
        vector<string> vs;
        string temp = "";
        for(int i = 0; i <= str.size(); i++) {
            if(str[i] == ' ' || i == str.size()) {
                vs.push_back(temp);
                temp = "";
            }
            else {
                temp += str[i];
            }
        }
        if(vs.size() != pattern.size())
            return false;
        for(int i = 0; i < pattern.size(); i++) {
            string s = "", t = vs[i];
            s += pattern[i];
            if((mpp.count(s) && mpp[s] != t) || (mps.count(t) && mps[t] != s))
                return false;
            mpp[s] = t;
            mps[t] = s;
        }
        for(auto it1 : mpp) {
            if(it1.first != mps[it1.second])
                return false;
        }
        for(auto it2 : mps) {
            if(it2.first != mpp[it2.second])
                return false;
        }
        return true;
    }
};
