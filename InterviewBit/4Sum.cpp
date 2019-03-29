vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    set<vector<int>> st;
    map<int, vector<pair<int, int>>> mp;
    for(int i=0; i<A.size(); i++) {
        for(int j = i + 1; j<A.size(); j++) {
            mp[A[i] + A[j]].push_back({i, j});
        }
    }
    
    while(mp.size() > 0) {
        auto it = mp.begin();
        int temp = it -> first;
        if(mp.find(B - temp) != mp.end()) {
            for(int i=0; i < mp[temp].size(); i++) {
                for(int j=0; j<mp[B - temp].size(); j++) {
                    int i1 = (mp[temp][i]).first;
                    int j1 = (mp[temp][i]).second;
                    int i2 = (mp[B - temp][j]).first;
                    int j2 = (mp[B - temp][j]).second;
                    if(i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2) {
                        vector<int> v;
                        v.push_back(A[i1]); v.push_back(A[i2]); 
                        v.push_back(A[j1]); v.push_back(A[j2]); 
                        sort(v.begin(), v.end());
                        st.insert(v);
                    }
                }
            }
        }
        mp.erase(it);
    }
    auto it = st.begin();
    while(it != st.end()) {
        res.push_back(*it);
        it++;
    }
    return res;
}

