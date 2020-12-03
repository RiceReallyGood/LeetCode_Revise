#include "../definitions.h"


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *headeven = head, *headodd = head->next;
        ListNode *taileven = headeven, *tailodd = headodd;
        ListNode* p = headodd->next;

        while(p){
            taileven->next = p;
            taileven = p;
            p = p->next;

            if(!p) break;

            tailodd->next = p;
            tailodd = p;
            p = p->next;
        }

        taileven->next = headodd;
        return head;
    }
};