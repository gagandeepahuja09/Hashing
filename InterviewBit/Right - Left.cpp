vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int, int> mp;
    int n = A.size();
    vector<int> ret(n, 0);
    for(int i = 0; i < n; i++) {
        ret[i] -= mp[A[i]];
        mp[A[i]]++;
    }
    mp.clear();
    for(int i = n - 1; i >= 0; i--) {
        ret[i] += mp[A[i]];
        mp[A[i]]++;
    }
    return ret;
}

