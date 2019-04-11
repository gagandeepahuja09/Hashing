vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    map<string, int> mpB;
    int sz = 0;
    for(int i = 0; i < B.size(); i++) {
        mpB[B[i]]++;
        sz++;
    }
    vector<int> res;
    for(int i = 0; i < A.size(); i++) {
        map<string, int> mpA;
        int cnt = 0;
        for(int j = i; j + B[0].size() <= A.size() && cnt < sz; j += B[0].size()) {
            mpA[A.substr(j, B[0].size())]++;
            cnt++;
        }
        if(mpA == mpB)
            res.push_back(i);
    }
    return res;
}

