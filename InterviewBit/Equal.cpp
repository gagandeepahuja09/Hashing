vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int, pair<int, int>> mp;
    vector<int> ret;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            int sum = A[i] + A[j];
            if(mp.find(sum) != mp.end()) {
                int x = mp[sum].first, y = mp[sum].second;
                if(x != i && x != j && x != y && y != i && y != j) {
                    vector<int> v = { x, y, i, j };
                    if(ret.size() == 0 || v < ret)
                        ret = v;
                }
            }
            else
                mp[sum] = { i, j };
        }
    }
    return vector<int>(ret.begin(), ret.end());
}
