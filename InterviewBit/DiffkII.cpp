int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int, int> mp;
    for(int i = 0; i < A.size(); i++) {
        if(mp[A[i] - B] || mp[A[i] + B])
            return 1;
        mp[A[i]]++;
    }
    return 0;
}

