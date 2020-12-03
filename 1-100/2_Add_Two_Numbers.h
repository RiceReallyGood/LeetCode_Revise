#include "../definitions.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dumhead = new ListNode(0);
        ListNode* p = dumhead;
        int carry = 0;
        while(l1 || l2){
            int i1 = 0, i2 = 0;
            if(l1){
                i1 = l1->val;
                l1 = l1->next;
            }
            if(l2){
                i2 = l2->val;
                l2 = l2->next;
            }
            int sum = i1 + i2 + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            p = p->next;
        }
        if(carry)
            p->next = new ListNode(carry);
        return dumhead->next;
    }
};