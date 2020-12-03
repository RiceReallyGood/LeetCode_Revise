class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        connect(root->left);
        connect(root->right);
        Node* lt = root->left, *rt = root->right;
        while(lt){
            lt->next = rt;
            lt = lt->right;
            rt = rt->left;
        }
        return root;
    }
};