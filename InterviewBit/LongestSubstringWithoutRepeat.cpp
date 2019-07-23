int Solution::lengthOfLongestSubstring(string A) {
    vector<int> pos(256, -1);
    int mx = 0, start = -1;
    for(int i = 0; i < A.size(); i++) {
        start = max(start, pos[A[i]]);
        mx = max(mx, i - start);
        pos[A[i]] = i;
    }
    return mx;
}

