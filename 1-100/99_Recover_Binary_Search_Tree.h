#include "../definitions.h"
#include <climits>
#include <utility>

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* dumroot = new TreeNode(INT_MIN);
        dumroot->right = root;
        TreeNode *bugnode1 = nullptr, *bugnode2 = nullptr;
        TreeNode *p = root, *lastnode = dumroot;
        while(p){
            TreeNode* prevnode = PrevNode(p);
            if(prevnode && prevnode->right == nullptr){
                prevnode->right = p;
                p = p->left;
            }
            else{
                if(prevnode) prevnode->right = nullptr;
                if(lastnode->val > p->val){
                    bugnode1 = bugnode1 == nullptr ? lastnode : bugnode1;
                    bugnode2 = p;
                }
                lastnode = p;
                p = p->right;
            }
        }
        std::swap(bugnode1->val, bugnode2->val);
    }

private:
    TreeNode* PrevNode(TreeNode* root){
        TreeNode* p = root->left;
        if(!p) return p;
        while(p->right && p->right != root) p = p->right;
        return p;
    }
};