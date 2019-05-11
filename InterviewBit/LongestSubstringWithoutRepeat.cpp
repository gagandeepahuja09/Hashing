int Solution::lengthOfLongestSubstring(string A) {
    int start = -1, maxLen = 1;
    vector<int> pos(256, -1);
    for(int i = 0; i < A.size(); i++) {
        if(pos[A[i]] > start) {
            start = pos[A[i]];
        }
        maxLen = max(maxLen, i - start);
        pos[A[i]] = i;
    }
    return maxLen;
}

