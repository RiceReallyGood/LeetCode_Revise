#include "../definitions.h"
#include <stack>
using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = s.top();
        int ret = node->val;
        s.pop();
        node = node->right;
        while(node){
            s.push(node);
            node = node->left;
        }
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() { return !s.empty(); }

private:
    stack<TreeNode*> s;
};