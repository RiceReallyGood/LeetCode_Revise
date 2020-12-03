#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for(int i = 30; i >= 0; i--){
            int trial = res | (1 << i);
            mask = mask | (1 << i);
            bool foundpair = false;
            unordered_set<int> prefixes;
            for(int num : nums){
                int prefix = num & mask;
                if(prefixes.find(trial ^ prefix) != prefixes.end()){
                    foundpair = true;
                    break;
                }
                prefixes.insert(prefix);
            }
            if(foundpair) res = trial;
        }
        return res;
    }
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        root = new PrefixTreeNode();
        for(int num : nums)
            res = max(res, maxxor(num));
        destory(root);
        return res;
    }

private:
    class PrefixTreeNode{
    public:
        PrefixTreeNode() {}
        PrefixTreeNode* childs[2] = {nullptr};
    };

    PrefixTreeNode* root;
    void destory(PrefixTreeNode* root){
        if(!root) return;
        destory(root->childs[0]);
        destory(root->childs[1]);
        delete root;
    }

    int maxxor(int num){
        int mask = 0x40000000;
        PrefixTreeNode* node1 = root;
        PrefixTreeNode* node2 = root;

        int res = 0;
        while(mask){
            int bit = (mask & num) > 0;
            if(node1->childs[bit] == nullptr)
                node1->childs[bit] = new PrefixTreeNode();
            node1 = node1->childs[bit];

            if(node2->childs[1 - bit]){
                res |= mask;
                node2 = node2->childs[1 - bit];
            }
            else{
                node2 = node2->childs[bit];
            }
            mask >>= 1;
        }
        return res;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new PrefixTreeNode();
        for(int num : nums) add(num);
        int res = helper(root, root, 1);
        destory(root);
        return res;
    }

private:
    class PrefixTreeNode{
    public:
        PrefixTreeNode() :zero(nullptr), one(nullptr) {}
        PrefixTreeNode* zero;
        PrefixTreeNode* one;
    };

    PrefixTreeNode* root;
    
    void destory(PrefixTreeNode* root){
        if(!root) return;
        destory(root->zero);
        destory(root->one);
        delete root;
    }

    void add(int num){
        int mask = 0x40000000;
        PrefixTreeNode* node = root;

        while(mask != 0){
            if(mask & num){
                if(!node->one)
                    node->one = new PrefixTreeNode();
                node = node->one;
            }
            else{
                if(!node->zero)
                    node->zero = new PrefixTreeNode();
                node = node->zero;
            }
            mask >>= 1;
        }
    }

    int helper(PrefixTreeNode* node1, PrefixTreeNode* node2, int level){
        if(level == 32) return 0;
        if((!node1->one && !node2->one) || (!node1->zero && !node2->zero)){
            if(node1->zero) return helper(node1->zero, node2->zero, level + 1);
            if(node1->one) return helper(node1->one, node2->one, level + 1);
        }
        else{
            int mask = 1 << (31 - level);
            int res = 0;
            if(node1->zero && node2->one)
                res = max(res, helper(node1->zero, node2->one, level + 1));
            if(node1->one && node2->zero)
                res = max(res, helper(node1->one, node2->zero, level + 1));
            return res | mask;
        }
        return 0;
    }
};