class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < A.size(); i++) { 
            sum += A[i];
            if(mp.find(A[i]) == mp.end())
                mp[A[i]] = i;
        }
        for(auto b : B)
            sum -= b;
        sum /= 2;
        for(int i = 0; i < B.size(); i++) {
            if(mp.find(B[i] + sum) != mp.end()) {
                return { B[i] + sum, B[i] };
            }
        }
        return { 0, 0 };
    }
};
