#include "../definitions.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dumhead = new ListNode(-1);
        dumhead->next = head;
        ListNode* tail = dumhead;
        ListNode* first = head, *second = head ? head->next : nullptr;
        while(second){
            first->next = second->next;
            second->next = first;
            tail->next = second;
            tail = first;
            first = tail->next;
            second = first ? first->next : nullptr;
        }
        head = dumhead->next;
        delete dumhead;
        return head;
    }
};