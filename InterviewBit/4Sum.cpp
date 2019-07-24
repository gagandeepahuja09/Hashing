vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    unordered_map<int, vector<pair<int, int>>> mp;
    set<vector<int>> ret;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            int target = B - A[i] - A[j];
            if(mp.find(target) != mp.end()) {
                vector<pair<int, int>> v = mp[target];
                for(int k = 0; k < v.size(); k++) {
                    int a = i, b = j, c = v[k].first, 
                    d = v[k].second;
                    if(a != b && a != c && a != d && b != c && b != d && c != d) {
                        vector<int> temp = { A[a], A[b], A[c], A[d] };
                        sort(temp.begin(), temp.end());
                        ret.insert(temp);
                    }
                }
            }
            mp[A[i] + A[j]].push_back({ i, j });
        }
    }
    return vector<vector<int>>(ret.begin(), ret.end());
}
