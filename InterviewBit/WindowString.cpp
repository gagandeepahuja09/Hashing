string Solution::minWindow(string s, string pat) {
    int n = pat.size();
    int start = 0, cnt = 0, mn = INT_MAX, fs = 0;
    vector<int> cs(256, 0);
    vector<int> cp(256, 0);
    for(int i = 0; i < pat.size(); i++) {
        cp[pat[i]]++;
    }
    for(int i = 0; i < s.size(); i++) {
        if(cs[s[i]] < cp[s[i]])
            cnt++;
        cs[s[i]]++;    
        while(cnt == n) {
            if(mn > i - start + 1) {
                mn = i - start + 1;
                fs = start;
            }
            cs[s[start]]--;
            if(cs[s[start]] < cp[s[start]])
                cnt--;
            start++;    
        }    
    }
    return mn == INT_MAX ? "" : s.substr(fs, mn);
}
