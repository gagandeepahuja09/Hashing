/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int cnt = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < G.size(); i++) {
            mp[G[i]]++;
        }
        while(head) {
            if(mp[head -> val]) {
                while(head && mp[head -> val])
                    head = head -> next;
                cnt++;
            }
            else {
                head = head -> next;
                // cnt++;
            }
        }
        return cnt;
    }
};
