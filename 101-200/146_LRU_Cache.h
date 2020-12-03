#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity), sz(0) {
        dumhead = new ListNode(-1, -1);
        dumhead->next = dumhead;
        dumhead->prev = dumhead;
    }
    
    int get(int key) {
        if(nodemap.find(key) == nodemap.end())
            return -1;
        
        move2front(nodemap[key]);
        return nodemap[key]->val;
    }
    
    void put(int key, int value) {
        if(nodemap.find(key) != nodemap.end()){
            nodemap[key]->val = value;
            move2front(nodemap[key]);
        }
        else{
            if(sz == cap){
                ListNode* tail = dumhead->prev;
                nodemap.erase(tail->key);
                tail->key = key;
                tail->val = value;
                nodemap[key] = tail;
                move2front(tail);
            }
            else{
                push(key, value);
                nodemap[key] = dumhead->next;
                sz++;
            }
        }
    }

private:
    class ListNode{
    public:
        ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
    };

    int cap;
    int sz;
    ListNode* dumhead;

    void push(int k, int v){
        ListNode* p = new ListNode(k, v);
        p->next = dumhead->next;
        p->prev = dumhead;
        dumhead->next->prev = p;
        dumhead->next = p;
    }

    void move2front(ListNode* p){
        if(dumhead->next == p) return;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = dumhead->next;
        p->prev = dumhead;
        dumhead->next->prev = p;
        dumhead->next = p;   
    }

    std::unordered_map<int, ListNode*> nodemap;
};