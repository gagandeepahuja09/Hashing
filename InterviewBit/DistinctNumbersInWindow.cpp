vector<int> Solution::dNums(vector<int> &A, int k) {
    map<int, int> mp;
    vector<int> res;
    int cnt = 0;
    for(int i=0; i<k; i++) {
        if(!mp[A[i]])
            cnt++;
        mp[A[i]]++;
    }
    res.push_back(cnt);
    for(int i=k; i<A.size(); i++) {
        // It it was a distinct element then remove count
        if(mp[A[i- k]] == 1) {
            cnt--;
        }
        mp[A[i-k]]--;
        // If it is not already in window
        if(mp[A[i]] == 0)
            cnt++;
        mp[A[i]]++;    
        res.push_back(cnt);
    }
    return res;
}

