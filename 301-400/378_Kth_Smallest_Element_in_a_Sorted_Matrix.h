#include <vector>
#include <queue>
using namespace std;

class Solution { //klog(n) 最坏时是 n^2log(n)
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Node> pq;
        pq.push(Node(matrix[0][0], 0, 0));

        for(int i = 1; i < k; i++){
            Node node = pq.top();
            pq.pop();
            if(node.col + 1 < n)
                pq.push(Node(matrix[node.row][node.col + 1], node.row, node.col + 1));
            
            if(node.col  == 0 && node.row + 1 < n)
                pq.push(Node(matrix[node.row + 1][0], node.row + 1, 0));
        }

        return pq.top().val;
    }

private:
    class Node{
        friend bool operator<(const Node& n1, const Node& n2) { return n1.val > n2.val; }
    public:
        Node(int v, int row_, int col_) : val(v), row(row_), col(col_) {}
        int val;
        int row;
        int col;
    };
};

class Solution { //nlog(r - l)
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];

        while(l < r){
            int c = l + (r - l) / 2;
            int count = 0;

            int i = n - 1, j = 0;
            while(i >= 0){
                while(j < n && matrix[i][j] <= c)
                    j++;
                count += j;
                i--;
            }

            if(count < k) l = c + 1;
            else r = c;
        }
        return l;
    }
};