class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ret;
        unordered_set<string> st(folder.begin(), folder.end());
        for(string s : folder) {
            string curr;
            bool flag = true;
            for(int i = 0; i < s.size(); i++) {
                curr += s[i];
                if(i != s.size() - 1 && s[i + 1] == '/'
                   && st.find(curr) != st.end()) {
                    // cout << "y" << endl;
                    flag = false;
                }
                // cout << curr << endl;
            }
            if(flag)
                ret.push_back(s);
        }
        return ret;
    }
};
