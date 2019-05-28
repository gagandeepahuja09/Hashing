/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

    Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'

    Note: All inputs will be in lower-case. 

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]

*/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<string, vector<int>> mp;
    for(int i = 0; i < A.size(); i++) {
        vector<int> cnt(26, 0);
        for(int j = 0; j < A[i].size(); j++) {
            cnt[A[i][j] - 'a']++;
        }
        string s = "";
        for(int j = 0; j < 26; j++) {
            s += (cnt[j] + '.'); 
        }
        mp[s].push_back(i + 1);
    }
    vector<vector<int>> ret;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        vector<int> v = it -> second;
        ret.push_back(v);
    }
    return ret;
}

