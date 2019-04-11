vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int, pair<int, int>> mp;
    vector<int> ans;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            int sum = A[i] + A[j];
            if(mp.find(sum) == mp.end())
                mp[A[i] + A[j]] = { i, j };
            else {
                pair<int, int> p = mp[sum];
                if(p.first < i && p.second != i && p.second != j) {
                    vector<int> temp;
                    temp.push_back(p.first);
                    temp.push_back(p.second);
                    temp.push_back(i);
                    temp.push_back(j);
                    
                    if(ans.size() == 0)
                        ans = temp;
                    else {
                        for(int k = 0; k < ans.size(); k++) {
                            if(ans[i] < temp[i])
                                break;
                            if(ans[i] > temp[i]) {
                                temp = ans;
                                break;
                            }    
                        }
                    }    
                }
            }    
        }
    }
    return ans;
}

