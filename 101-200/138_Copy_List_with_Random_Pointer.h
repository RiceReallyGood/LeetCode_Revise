#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> nodemap;
        nodemap[head] = new Node(head->val);
        Node* node = head;
        while(node->next){
            nodemap[node]->next = new Node(node->next->val);
            nodemap[node->next] = nodemap[node]->next;
            node = node->next;
        }
        node = head;
        while(node){
            nodemap[node]->random = nodemap[node->random];
            node = node->next;
        }

        return nodemap[head];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> nodemap;
        Node* node = head;
        while(node){
            nodemap[node] = new Node(node->val);
            node = node->next;
        }

        node = head;
        while(node){
            nodemap[node]->next = nodemap[node->next];
            nodemap[node]->random = nodemap[node->random];
            node = node->next;
        }
        return nodemap[head];
    }
};