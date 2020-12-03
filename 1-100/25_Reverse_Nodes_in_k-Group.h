#include "../definitions.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode * p = head;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        if(len < k) return head;

        ListNode* dumhead = new ListNode(-1);
        dumhead->next = head;     
        ListNode* tail = dumhead;
        ListNode *p1, *p2;
        for(int i = 0; i < len / k; i++){
            p1 = tail->next;
            for(int j = 0; j < k - 1; j++){
                p2 = p1->next;
                p1->next = p2->next;
                p2->next = tail->next;
                tail->next = p2;
            }
            tail = p1;
        }
        head = dumhead->next;
        delete dumhead;
        return head;
    }
};