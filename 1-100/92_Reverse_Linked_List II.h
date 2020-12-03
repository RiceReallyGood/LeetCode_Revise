#include "../definitions.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dumhead = new ListNode(0);
        dumhead->next = head;
        ListNode *tail = dumhead;
        for(int i = 0; i < m - 1; i++)
            tail = tail->next;
        
        ListNode *p1 = tail->next, *p2;
        for(int i = 0; i < n - m; i++){
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = tail->next;
            tail->next = p2;
        }
        return dumhead->next;
    }
};