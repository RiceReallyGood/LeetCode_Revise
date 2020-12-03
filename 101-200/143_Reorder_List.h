#include "../definitions.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *p1 = head, *p2 = head->next;
        while(p2 && p2->next){
            p2 = p2->next->next;
            p1 = p1->next;
        }
        p2 = reverse(p1->next);
        p1->next = nullptr;
        p1 = head;
        while(p2){
            ListNode* temp = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next->next;
            p2 = temp;
        }
    }

private:
    ListNode* reverse(ListNode* head){
        if(head == nullptr) return nullptr;
        ListNode* p = head;
        while(p->next){
            ListNode* temp = p->next;
            p->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};