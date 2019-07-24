/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
unordered_map<RandomListNode*, RandomListNode*> mp; 
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    if(!head)
        return head;
    if(mp[head])
        return mp[head];
    RandomListNode* copy = new RandomListNode(head -> label);
    mp[head] = copy;
    copy -> next = copyRandomList(head -> next);
    copy -> random = copyRandomList(head -> random);
    return copy;
}

