#include "../definitions.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumhead = new ListNode(-1);
        dumhead->next = head;
        ListNode* p = head;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        p = dumhead;
        for(int i = 0; i < len - n; i++)
            p = p->next;
        p->next = p->next->next;
        return dumhead->next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumhead = new ListNode(-1);
        dumhead->next = head;
        ListNode* fast = dumhead, *slow = dumhead;
        for(int i = 0; i < n + 1; i++)
            fast = fast->next;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        head = dumhead->next;
        delete dumhead;
        return head;
    }
};