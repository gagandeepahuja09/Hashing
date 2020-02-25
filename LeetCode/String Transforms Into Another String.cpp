/* 

Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.

Return true if and only if you can transform str1 into str2.

 

Example 1:

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.

Example 2:

Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.

*/

class Solution {
public:
    bool canConvert(string s1, string s2) {
        if(s1 == s2)
            return true;
        unordered_map<char, char> mp;
        int cnt = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(mp.find(s1[i]) != mp.end() && mp[s1[i]] != s2[i]) {
                return false;
            }
                mp[s1[i]] = s2[i];
        }
        return set(s2.begin(), s2.end()).size() < 26;
    }
};
