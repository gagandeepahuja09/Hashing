string Solution::minWindow(string B, string A) {
    unordered_map<char, int> mpA, mpB;
    int currStart = 0, start = -1, cnt = 0, minLen = INT_MAX;
    for(int i = 0; i < A.size(); i++) {
        mpA[A[i]]++;
    }
    for(int i = 0; i < B.size(); i++) {
        mpB[B[i]]++;
        if(mpB[B[i]] <= mpA[B[i]]) {
            cnt++;
        }
        if(cnt == A.size()) {
            while(mpB[B[currStart]] > mpA[B[currStart]]) {
                if(mpA[B[currStart]])
                    mpB[B[currStart]]--;
                currStart++;
            }
            int len = i - currStart + 1;
            if(len < minLen) {
                minLen = len;
                start = currStart;
            }
        }
    }
    if(start == -1)
        return "";
    return B.substr(start, minLen);    
}

