#include "../definitions.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dumhead = new ListNode(0);
        dumhead->next = head;
        ListNode *p = dumhead, *tail = dumhead;
        while(p->next){
            if(p->next->val < x){
                if(p == tail){
                    tail = p = p->next;
                }
                else{
                    ListNode* temp = p->next;
                    p->next = temp->next;
                    temp->next = tail->next;
                    tail->next = temp;
                    tail = temp;
                }
            }
            else
                p = p->next;
        }
        return dumhead->next;
    }
};