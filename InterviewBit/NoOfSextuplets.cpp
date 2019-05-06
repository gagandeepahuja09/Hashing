/*Given an array of integers A, find the number of sextuplets that satisfy the equation (a * b + c) / d - e = f.
where a, b, c, d, e, f belong to the given array A.*/

#define ll long long int
#define MOD 1000000007

int Solution::solve(vector<int> &A) {
    unordered_map<ll, int> mp;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            for(int k = 0; k < A.size(); k++) {
                if(A[i]) {
                    ll ans = A[i] * (A[j] + A[k]);
                    mp[ans]++;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            for(int k = 0; k < A.size(); k++) {
                ll curr = A[i] * A[j] + A[k];
                ans = (ans % MOD + mp[curr] % MOD) % MOD;
            }
        }
    }
    return (int)ans;
}

