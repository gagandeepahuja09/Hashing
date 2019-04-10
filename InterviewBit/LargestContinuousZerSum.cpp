vector<int> Solution::lszero(vector<int> &A) {
    map<int, int> mp;
    int maxSeq = -1, start = -1, sum = 0;
    mp[sum] = 0;
    for(int i = 0; i < A.size(); i++) {
        sum += A[i];
        if(mp.find(sum) == mp.end())
            mp[sum] = i + 1;
        else {
            if(maxSeq < i - mp[sum]) {
                maxSeq = i - mp[sum];
                start = mp[sum];
            }
        }    
    }
    vector<int> ret;
    if(maxSeq == -1) 
        return ret;
    for(int i = start; i <= start + maxSeq; i++)
        ret.push_back(A[i]);
    return ret;    
}

