#include "../definitions.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dumhead = new ListNode(0);
        dumhead->next = head;
        ListNode * p = head, *prev = dumhead;
        while(p){
            if(p->next && p->next->val == p->val){
                int v = p->val;
                while(p && p->val == v) p = p->next;
            }
            else{
                prev->next = p;
                prev = p;
                p = p->next;
            }
        }
        prev->next = nullptr;
        return dumhead->next;
    }
};