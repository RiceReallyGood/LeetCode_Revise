#include <queue>
#include "../definitions.h"
using namespace std;


//use heap sort O(N log k) where N is the total elements number
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode* dumhead = new ListNode(-1);
        for(ListNode* p : lists){
            if(p) pq.push(p);
        }

        ListNode* p = dumhead;
        while(!pq.empty()){
            p->next = pq.top();
            pq.pop();
            p = p->next;
            if(p->next)
                pq.push(p->next);
        }
        p = dumhead->next;
        delete dumhead;
        return p;
    }

private:
    class comp{
    public:
        bool operator()(ListNode* p1, ListNode* p2){
            return p1->val > p2->val;
        }
    };
};

//merge recursively O(N log k)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l == r) return lists[l];
        int c = l + (r - l) / 2;
        ListNode* first = merge(lists, l, c);
        ListNode* second = merge(lists, c + 1, r);
        ListNode* dumhead = new ListNode(-1);
        ListNode* p = dumhead;
        while(first && second){
            if(first->val < second->val){
                p->next = first;
                first = first->next;
            }
            else{
                p->next = second;
                second = second->next;
            }
            p = p->next;
        }
        p->next = first ? first : second;
        p = dumhead->next;
        delete dumhead;
        return p;
    }
};