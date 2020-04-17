#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MX 100005
 
int main() {
    ll n, sum = 0, total = 0, ans = 0;
    cin >> n;
    vector<ll> a(n), cnt(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    if(total % 3) {
        cout << 0 << endl;
        return 0;
    }
    for(ll i = n - 1; i >= 0; i--) {
        sum += a[i];
        cnt[i] = (i < n - 1 ? cnt[i + 1] : 0) + (sum == total / 3);
    }
    sum = 0;
    for(ll i = 0; i < n; i++) {
        sum += a[i];
        if(sum == total / 3 && i + 2 < n) {
            ans += cnt[i + 2];
        }
    }
    cout << ans << endl;
}
