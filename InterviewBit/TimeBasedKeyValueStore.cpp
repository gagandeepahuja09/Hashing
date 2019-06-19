/*
Time Based Key-Value Store

You are required to perform N operations where each operation is of either type 1 or type 2.

You are given the following input:

An array of integers A that describes the type of ith operation.

An array of strings B that describes the key in the ith operation.

An array of strings C that describes the value in the ith operation.

An array of integers D that describes the timestamp in the ith operation.

Operations are of the following form:

Type 1: set(string key, string value, int timestamp)

    Stores the key and value, along with the given timestamp. where key = B[i], value = C[i], timestamp = D[i].

After Performing type 1 operation return "null".

Type 2: get(string key, int timestamp)

where key = B[i], timestamp = D[i] .

    Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
    If there are multiple such values, it returns the one with the largest timestamp_prev.
    If there are no values, it returns "null".

A[i] determines the type of operation if it is equal to 1 then you have to perform type 1 operations else you have to perform type 2 operation.

Return an array of the strings after performing all N operations.

    A = [1, 2, 2, 1, 2, 2]
    B = ["foo", "foo", "foo", "foo", "foo", "foo"]
    C = ["bar", "null", "null", "bar2", "null", "null"]
    D = [1, 1, 3, 4, 4, 5]
Output 1:
    ["null", "bar", "bar", "null", "bar2", "bar2"]
    Explanation 1:
        Operation 1: set("foo", "bar", 1) returns "null".
        Operation 2: get("foo", 1) returns "bar" as it has maximum value <= 1 with key as "foo".
        Operation 3: get("foo", 3) returns "bar" as it has maximum value <= 3 with key as "foo".
        Operation 4: set("foo", "bar2", 4) returns "null".
        Operation 5: get("foo", 4) returns "bar2" as it has maximum value <= 4 with key as "foo".
        Operation 6: get("foo", 5) returns "bar2" as it has maximum value <= 5 with key as "foo".



Input 2:
    A = [1, 1, 2, 2, 2, 2, 2]
    B = ["love", "love", "love", "love", "love", "love", "love"]
    C = ["high", "low", "null", "null", "null", "null", "null"]
    D = [10, 20, 5, 10, 15, 20, 25]
Output 2:
    ["null", "null", "null", "high", "high", "low", "low"]
*/

void Set(string key, string val, int tm, unordered_map<string, map<int, string>>& mp) {
    mp[key][tm] = val;
}

string get(string key, int tm, unordered_map<string, map<int, string>>& mp) {
    if(mp.find(key) == mp.end())
        return "null";
    auto it = mp[key].upper_bound(tm);
    if(it == mp[key].begin())
        return "null";
    return prev(it) -> second;    
}

vector<string> Solution::solve(vector<int> &A, vector<string> &B, vector<string> &C, vector<int> &D) {
    vector<string> ret;
    unordered_map<string, map<int, string>> mp;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 1) {
            Set(B[i], C[i], D[i], mp);
            ret.push_back("null");
        }
        else {
            ret.push_back(get(B[i], D[i], mp));
        }
    }
    return ret;
}

