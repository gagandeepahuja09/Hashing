/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    RandomListNode* curr = head;
    while(head) {
        RandomListNode* temp = head -> next;
        head -> next = new RandomListNode(head -> label);
        head -> next -> next = temp;
        head = head -> next -> next;
    }
    head = curr;
    while(head && head -> next) {
        if(head -> random)
            head -> next -> random = head -> random -> next;
        head = head -> next -> next;
    }
    head = curr -> next;
    RandomListNode* newHead = head;
    while(head) {
        if(head->next)
        head -> next = head -> next -> next;
        else
            return newHead;
        head = head -> next;
    }
    return newHead;
}

