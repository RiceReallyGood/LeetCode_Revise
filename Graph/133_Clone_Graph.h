#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* m[101] = {nullptr};
        return dfs(node, m);
    }

private:
    Node* dfs(Node* node, Node* m[]){
        int v = node->val;
        if(m[v] == nullptr){
            m[v] = new Node(v);

            for(auto neighbour : node->neighbors){
                m[v]->neighbors.push_back(dfs(neighbour, m));
            }
        }
        return m[v];
    }
};