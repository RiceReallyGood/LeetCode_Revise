#include "../definitions.h"
#include <random>

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head_) : head(head_) {
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = head;
        int ret = 0;
        int count = 0;
        while(node){
            if(rand() % (++count) == 0)
                ret = node->val;
            node = node->next;
        }
        return ret;
    }
private:
    ListNode* head;
};