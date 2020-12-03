#include "../definitions.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        while(head->next){
            ListNode* temp = head->next;
            head->next = temp->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};