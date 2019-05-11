/*
Palindrome Pairs

Given a list of unique words A, find all pairs of distinct indices 
(i,j) in the given list such that concatenation of the two words, i.e. A[i] + A[j] is a 
palindrome. */

// O(N * len * len)

bool isPalin(string s) {
    if(!s.size())
        return false;
    int l = 0, r = s.size() - 1;
    while(l < r) {
        if(s[l] != s[r])
            return false;
        l++; r--;    
    }
    return true;
}

vector<vector<int> > Solution::solve(vector<string> &A) {
    vector<vector<int>> res;
    unordered_map<string, int> mp;
    for(int i = 0; i < A.size(); i++) {
        mp[A[i]] = i;
    }
    for(int i = 0; i < A.size(); i++) {
        string s = A[i];
        string curr = s;
        string rev = curr;
        reverse(rev.begin(), rev.end());
        if(mp.find(rev) != mp.end() && mp[rev] != i) {
            vector<int> v = { i, mp[rev] };
            if(!res.size() || res.back() != v)
                res.push_back(v);
        }
        string start = "";
        for(int k = 0; k < s.size(); k++) {
            start += s[k];
            curr = curr.substr(1);
            string revEnd = curr;
            string revStart = start;
            reverse(revEnd.begin(), revEnd.end());
            reverse(revStart.begin(), revStart.end());
            if(isPalin(start) && mp.find(revEnd) != mp.end() && mp[revEnd] != i) {
                vector<int> v = { mp[revEnd], i };
                if(!res.size() || res.back() != v)
                    res.push_back(v);
            }
            if(isPalin(curr) && mp.find(revStart) != mp.end() && mp[revStart] != i) {
                vector<int> v = { i, mp[revStart] };
                if(!res.size() || res.back() != v)
                    res.push_back(v);
            }
        }
    }
    return res;
}

