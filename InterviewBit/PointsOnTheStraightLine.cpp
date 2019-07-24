int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int mx = 0;
    for(int i = 0; i < A.size(); i++) {
        unordered_map<string, int> mp;
        int duplicates = 1;
        for(int j = i + 1; j < A.size(); j++) {
            if(A[i] == A[j] && B[i] == B[j])
                duplicates++;
            else {
                int dx = A[j] - A[i], dy = B[j] - B[i];
                int g = __gcd(dx, dy);
                string s = to_string(dx / g) + '_' + to_string(dy / g);
                mp[s]++;
            }    
        }
        mx = max(mx, duplicates);
        for(auto it = mp.begin(); it != mp.end(); it++) {
            mx = max(mx, it -> second + duplicates);
        }
    }
    return mx;
}

