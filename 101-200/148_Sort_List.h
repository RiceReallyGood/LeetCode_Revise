#include "../definitions.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *h2 = head->next, *h1 = head;
        while(h1 && h1->next){
            h2 = h2->next->next;
            h1 = h1->next;
        }
        h2 = h1->next;
        h1->next = nullptr;

        h1 = sortList(head);
        h2 = sortList(h2);
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(h1 && h2){
            if(h1->val < h2->val){
                tail->next = h1;
                h1 = h1->next;
            }
            else{
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }
        if(h1) tail->next = h1;
        if(h2) tail->next = h2;
        head = dummy->next;
        delete dummy;
        return head;
    }
};