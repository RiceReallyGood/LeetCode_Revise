#include "../definitions.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while(p){
            while(p->next && p->next->val == p->val){
                p->next = p->next->next;
            }
            p = p->next;
        }
        return head;
    }
};