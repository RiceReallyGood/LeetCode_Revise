#include <vector>
using namespace std;

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
        vector<Node*> right;
        return recurse(root, right, 0);
    }

private:
    Node* recurse(Node* root, vector<Node*>& right, int depth){
        if(root == nullptr) return nullptr;
        if(depth == right.size())
            right.push_back(root);
        else{
            root->next = right[depth];
            right[depth] = root;
        }

        recurse(root->right, right, depth + 1);
        recurse(root->left, right, depth + 1);
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* dumhead = new Node(0);
        dumhead->next = root;
        while(dumhead->next){
            Node* p = dumhead->next;
            Node* prev = dumhead;
            dumhead->next = nullptr;
            while(p){
                if(p->left){
                    prev->next = p->left;
                    prev = p->left;
                }
                if(p->right){
                    prev->next = p->right;
                    prev = p->right;
                }
                p = p->next;
            }
        }
        delete dumhead;
        return root;
    }
};