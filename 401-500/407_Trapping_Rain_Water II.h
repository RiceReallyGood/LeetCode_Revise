#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() < 3 || heightMap[0].size() < 3) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            pq.push(Node(heightMap[i][0], i, 0));
            visited[i][0] = true;
            pq.push(Node(heightMap[i][n - 1], i, n - 1));
            visited[i][n - 1] = true;
        }

        for(int j = 1; j < n - 1; j++){
            pq.push(Node(heightMap[0][j], 0, j));
            visited[0][j] = true;
            pq.push(Node(heightMap[m - 1][j], m - 1, j));
            visited[m - 1][j] = true;
        }

        int h = 0, ret = 0;
        while(!pq.empty()){
            Node node = pq.top();
            pq.pop();
            h = max(h, node.height);
            ret += h - node.height;

            int i = node.row, j = node.col;
            if(i > 0 && !visited[i - 1][j]){
                pq.push(Node(heightMap[i - 1][j], i - 1, j));
                visited[i - 1][j] = true;
            }
            
            if(i < m - 1 && !visited[i + 1][j]){
                pq.push(Node(heightMap[i + 1][j], i + 1, j));
                visited[i + 1][j] = true;
            }
            
            if(j > 0 && !visited[i][j - 1]){
                pq.push(Node(heightMap[i][j - 1], i, j - 1));
                visited[i][j - 1] = true;
            }

            if(j < n - 1 && !visited[i][j + 1]){
                pq.push(Node(heightMap[i][j + 1], i, j + 1));
                visited[i][j + 1] = true;
            }
        }

        return ret;
    }

private:
    struct Node{
        Node(int height_, int i, int j) : height(height_), row(i), col(j) {}
        friend bool operator>(const Node& n1, const Node& n2){
            return n1.height > n2.height;
        }
        int height;
        int row;
        int col;
    };
};