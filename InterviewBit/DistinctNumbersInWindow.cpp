vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    vector<int> ret;
    int cnt = 0;
    for(int i = 0; i < B && i < A.size(); i++) {
        if(!mp[A[i]]++)
            cnt++;    
    }
    ret.push_back(cnt);
    for(int i = B; i < A.size(); i++) {
        if(!mp[A[i]]++)
            cnt++;
        if(mp[A[i - B]]-- == 1)
            cnt--;    
        ret.push_back(cnt);    
    }
    return ret;
}

