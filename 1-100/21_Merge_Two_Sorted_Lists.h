#include "../definitions.h"
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dumhead = new ListNode(-1);
        ListNode* p = dumhead;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        p->next = l1 ? l1 : l2;
        p = dumhead->next;
        delete dumhead;
        return p;
    }
};