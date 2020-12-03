#include "../definitions.h"
#include <climits>

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dumhead = new ListNode(INT_MIN);
        dumhead->next = head;
        ListNode* tail = dumhead;
        while(head){
            if(head->val >= tail->val){
                tail = head;
                head = head->next;
                continue;
            }
            ListNode* p = dumhead;
            while(p->next->val < head->val){
                p = p->next;
            }
            tail->next = head->next;
            head->next = p->next;
            p->next = head;
            head = tail->next;
        }
        head = dumhead->next;
        delete dumhead;
        return head;
    }
};