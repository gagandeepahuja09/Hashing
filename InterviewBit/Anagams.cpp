vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<string, vector<int>> mp;
    for(int i = 0; i < A.size(); i++) {
        string temp = A[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(i + 1);
    }
    vector<vector<int>> res;
    auto it = mp.begin();
    while(it != mp.end()) {
        res.push_back(it -> second);
        it++;
    }
    return res;
}

