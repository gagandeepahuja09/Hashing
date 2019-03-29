vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> mp;
    vector<int> res;
    for(int i=0; i<A.size(); i++) {
        if(mp.find(B - A[i]) != mp.end()) {
            for(int j = 0; j < i; j++) {
                if(A[j] == B - A[i]) {
                    res.push_back(j + 1);
                    res.push_back(i + 1);
                    return res;
                }
            }
        }
        mp[A[i]] = 1;
    }
}

