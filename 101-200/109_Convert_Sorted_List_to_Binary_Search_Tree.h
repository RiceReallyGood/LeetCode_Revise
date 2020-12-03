#include "../definitions.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p){
            len++;
            p = p->next;
        }
        return ListToBalancedTree(head, 0, len - 1);
    }

private:
    TreeNode* ListToBalancedTree(ListNode* &p, int l, int r){
        if(l > r) return nullptr;
        int c = l + (r - l) / 2;
        TreeNode* root = new TreeNode(0);
        root->left = ListToBalancedTree(p, l, c - 1);
        root->val = p->val;
        p = p->next;
        root->right = ListToBalancedTree(p, c + 1, r);
        return root;
    }
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p){
            len++;
            p = p->next;
        }
        return ListToBalancedTree(head, 0, len);
    }

private:
    TreeNode* ListToBalancedTree(ListNode* &p, int l, int r){
        if(l == r) return nullptr;
        int c = l + (r - l) / 2;
        TreeNode* root = new TreeNode(0);
        root->left = ListToBalancedTree(p, l, c);
        root->val = p->val;
        p = p->next;
        root->right = ListToBalancedTree(p, c + 1, r);
        return root;
    }
};