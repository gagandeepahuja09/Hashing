/*
Sort an array according to the order defined by another array

Given two array of integers A and B, Sort A in such a way that the relative order among the elements will be the same as those are in B. For the elements not present in B, append them at last in sorted order.

Return the array A after sorting from the above method.

Note: Elements of B are unique.

Input 1:
    A = [1, 2, 3, 4, 5]
    B = [5, 4, 2]
Output 1:
    A = [5, 4, 2, 1, 3]

Input 2:
    A = [5, 17, 100, 11]
    B = [1, 100]
Output 2:
    [100, 5, 11, 17]*/


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> mp;
    vector<int> ret;
    for(int i = 0; i < A.size(); i++) {
        mp[A[i]]++;
    }
    for(int i = 0; i < B.size(); i++) {
        while(mp[B[i]]) {
            ret.push_back(B[i]);
            mp[B[i]]--;
        }
    }
    vector<int> v;
    for(int i = 0; i < A.size(); i++) {
        if(mp[A[i]])
            v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        ret.push_back(v[i]);
    return ret;
}

