#include <vector>
#include <queue>
#include <unordered_map>
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

class Solution { //dfs using a vector as a map
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        vector<Node*> copy(101, nullptr);
        return dfs(node, copy);
    }

private:
    Node* dfs(Node* node, vector<Node*>& copy){
        Node* cloned = new Node(node->val);
        copy[node->val] = cloned;
        for(Node* neighbour : node->neighbors){
            if(copy[neighbour->val] != nullptr){
                cloned->neighbors.push_back(copy[neighbour->val]);
            }
            else{
                cloned->neighbors.push_back(dfs(neighbour, copy));
            }
        }
        return cloned;
    }
};

class Solution { //dfs using a unordered map
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> nodemap;
        return dfs(node, nodemap);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& nodemap){
        if(nodemap.find(node) != nodemap.end())
            return nodemap[node];
        Node* cloned = new Node(node->val);
        nodemap[node] = cloned;
        for(Node* neighbour : node->neighbors){
            cloned->neighbors.push_back(dfs(neighbour, nodemap));
        }
        return cloned;
    }
};

class Solution { //bfs
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> nodemap;
        queue<Node*> q;
        q.push(node);
        nodemap[node] = new Node(node->val);
        while(!q.empty()){
            Node* p = q.front();
            q.pop();
            for(auto neighbour : p->neighbors){
                if(nodemap.find(neighbour) == nodemap.end()){
                    nodemap[neighbour] = new Node(neighbour->val);
                    q.push(neighbour);
                }
                nodemap[p]->neighbors.push_back(nodemap[neighbour]);
            }
        }
        return nodemap[node];
    }
};