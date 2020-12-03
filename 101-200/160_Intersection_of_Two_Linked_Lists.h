#include "../definitions.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;
        while(pA){
            lenA++;
            pA = pA->next;
        }
        pB = headB;
        while(pB){
            lenB++;
            pB = pB->next;
        }
        pA = headA, pB = headB;
        while(lenA > lenB){
            pA = pA->next;
            lenA--;
        }

        while(lenB > lenA){
            pB = pB->next;
            lenB--;
        }

        while(pA != pB){
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};