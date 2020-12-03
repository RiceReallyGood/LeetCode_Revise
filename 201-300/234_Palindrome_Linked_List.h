#include "../definitions.h"
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        vector<int> nums;

        while(head){
            nums.push_back(head->val);
            head = head->next;
        }

        for(int i = 0, j = nums.size() - 1; i < j; i++, j--)
            if(nums[i] != nums[j])
                return false;
        return true;
    }
};