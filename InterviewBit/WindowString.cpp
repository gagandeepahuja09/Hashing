string Solution::minWindow(string s, string pat) {
    map<char, int> mpS, mpPat;
    int l = 0, minLen = INT_MAX, start = 0, startIdx = -1;
    for(int i=0; i<pat.size(); i++) {
        mpPat[pat[i]]++;
    }
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        mpS[s[i]]++;
        if(mpPat[s[i]] != 0 && mpS[s[i]] <= mpPat[s[i]])
            cnt++;
        if(cnt == pat.length()) {
            while(mpS[s[start]] > mpPat[s[start]] > 0 
            || mpPat[s[start]] == 0) {
                if(mpS[s[start]] > mpPat[s[start]])
                    mpS[s[start]]--;
                start++;    
            }
            int len = i - start + 1;
            if(len < minLen) {
                minLen = len;
                startIdx = start;
            }
        }    
    }
    if(startIdx == -1)
        return "";
    return s.substr(startIdx, minLen);
}

