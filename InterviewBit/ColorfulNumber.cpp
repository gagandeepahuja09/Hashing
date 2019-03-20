#define ll long long int

int Solution::colorful(int A) {
    vector<int> v;
    while(A) {
        v.push_back(A%10);
        A /= 10;
    }
    unordered_map<ll, ll> mp;
    for(int i=0; i<v.size(); i++) {
        ll prod = 1;
        for(int j=i; j<v.size(); j++) {
            prod = prod * v[j];
            if(mp.find(prod) != mp.end())
                return 0;
            mp[prod] = 1;    
        }
    }
    return 1;
}

