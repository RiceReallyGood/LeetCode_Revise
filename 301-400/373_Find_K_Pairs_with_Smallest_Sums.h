#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty()) return {};
        auto comp = [](const Node& n1, const Node& n2){ return n1.val  > n2.val; };
        priority_queue<Node> pq;
        pq.push(Node(nums1[0] + nums2[0], 0, 0));

        vector<vector<int>> ret;

        while(!pq.empty() && ret.size() < k){
            Node n = pq.top();
            pq.pop();
            ret.push_back({nums1[n.i1], nums2[n.i2]});
            if(n.i2 + 1 < nums2.size())
                pq.push(Node(nums1[n.i1] + nums2[n.i2 + 1], n.i1, n.i2 + 1));
            
            if(n.i2 == 0 && n.i1 + 1 < nums1.size())
                pq.push(Node(nums1[n.i1 + 1] + nums2[n.i2], n.i1 + 1, n.i2));
        }

        return ret;
    }

private:
    class Node{
        friend bool operator<(const Node& n1, const Node& n2){ return n1.val > n2.val; }
    public:
        Node(int v, int i1_, int i2_) : val(v), i1(i1_), i2(i2_) {}
        int val;
        int i1;
        int i2;
    };
};