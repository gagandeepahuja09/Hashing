/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* curr = A;
    while(curr) {
        RandomListNode* temp = curr -> next;
        RandomListNode* newNode = new RandomListNode(curr -> label);
        curr -> next = newNode;
        newNode -> next = temp;
        curr = temp;
    }
    curr = A;
    while(curr) {
        if(curr -> next) {
            if(curr -> random) {
                curr -> next -> random = curr -> random -> next;
            }
        }
        curr = curr -> next ? curr -> next -> next : curr -> next;
    }
    RandomListNode* original = A, *copy = A -> next;
    curr = copy;
    while(original && copy) {
        if(original -> next)
            original -> next = original -> next -> next;
        if(copy -> next)
            copy -> next = copy -> next -> next;
        original = original -> next;
        copy = copy -> next;
    }
    return curr;
}
