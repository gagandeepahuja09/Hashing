class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        bool flag = false;
        for(string s : emails) {
            string temp = "";
            flag = false;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '.' && !flag)
                    continue;
                else if(s[i] == '+' && !flag) {
                    while(i < s.size() - 1 && s[i + 1] != '@') {
                        i++;
                    }
                }
                else if(s[i] == '@') {
                    flag = true;
                    temp += s[i];
                }
                else
                    temp += s[i];
            }
            // cout << temp << endl;
            st.insert(temp);
        }
        return st.size();
    }
};
