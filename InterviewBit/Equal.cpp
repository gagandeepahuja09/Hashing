/*Given an array A of integers, find the index of values that satisfy A + B = C + D, where
A,B,C & D are integers values in the array*/

#define ll long long int

vector<int> Solution::equal(vector<int> &A) {
    map<ll, pair<int, int>> mp;
    vector<int> res;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            if(mp.find(A[i] + A[j]) != mp.end()) {
                if(mp[A[i] + A[j]].first != i && mp[A[i] + A[j]].second != i && 
                mp[A[i] + A[j]].first != j && mp[A[i] + A[j]].second != j) {
                    vector<int> v = 
                    { mp[A[i] + A[j]].first, mp[A[i] + A[j]].second, i, j };
                    if(!res.size() || v < res)
                        res = v;
                }
            }
            else {
                mp[A[i] + A[j]] = { i, j };
            }
        }
    }
    return res;
}

