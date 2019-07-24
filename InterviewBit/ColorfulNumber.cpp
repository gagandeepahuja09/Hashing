int Solution::colorful(int A) {
    vector<int> v;
    unordered_map<int, int> mp;
    while(A) {
        v.push_back(A % 10);
        A /= 10;
    }
    for(int i = 0; i < v.size(); i++) {
        int prod = 1;
        for(int j = i; j < v.size(); j++) {
            prod *= v[j];
            if(mp.find(prod) != mp.end())
                return 0;
            mp[prod]++;    
        }
    }
    return 1;
}

