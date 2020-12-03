#include "../definitions.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head) return head;
        int len = 0;
        ListNode *p = head;
        while(p){
            len++;
            p = p->next;
        }
        k %= len;
        if(len == 1 || k == 0) return head;
        ListNode* fast = head, *slow = head;
        for(int i = 0; i < k; i++)
            fast = fast->next;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};