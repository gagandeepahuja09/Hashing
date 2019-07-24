vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int l = B[0].size();
    unordered_map<string, int> mp;
    for(int i = 0; i < B.size(); i++) {
        mp[B[i]]++;
    }
    vector<int> ret;
    int len = B.size() * B[0].size();
    for(int i = 0; i < A.size(); i++) {
        int j = i;
        unordered_map<string, int> mp2;
        while(j < i + len && j < A.size()) {
            mp2[A.substr(j, l)]++;
            j += l;
        }
        if(mp2 == mp)
            ret.push_back(i);
    }
    return ret;
}
