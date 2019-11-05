#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define MAX 200005

ll n;

int main() {
    // ll t;
    // cin >> t; while(t--) {
        cin >> n;
        vector<ll> x(n), y(n);
        unordered_map<ll, ll> mp1;
        unordered_map<ll, ll> mp2;
        map<pair<ll, ll>, ll> mpp;
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            mp1[x[i]]++;
            mp2[y[i]]++;
            mpp[{ x[i], y[i] }]++;
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            mpp[{ x[i], y[i] }]--;
            mp1[x[i]]--; mp2[y[i]]--;
            ans += (mp1[x[i]] + mp2[y[i]] - mpp[{ x[i], y[i] }]);
        }
        cout << ans << endl;
    // }
}
