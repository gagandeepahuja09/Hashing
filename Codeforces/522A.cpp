#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define MAX 200005

int main() {
unordered_map<string, ll> mp;
mp["polycarp"] = 1;
ll n, ans = 0;
cin >> n;
for(int i = 0; i <= n; i++) {
    string s;
    getline(cin, s);
    string s1, s2;
    int j = 0;
    for(j = 0; j < s.size(); j++) {
        if(s.substr(j, 10) == " reposted ") {
            s1 = s.substr(0, j);
            s2 = s.substr(j + 10);
            for(int k = 0; k < s1.size(); k++)
                s1[k] = tolower(s1[k]);
            for(int k = 0; k < s2.size(); k++)
                s2[k] = tolower(s2[k]);    
            mp[s1] = mp[s2] + 1;
            ans = max(ans, mp[s1]);
            break;
        }
    } 
}
cout << ans << endl;
}
