#include "../definitions.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while(p->next){
            if(p->next->val == val){
                ListNode* temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else{
                p = p->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};