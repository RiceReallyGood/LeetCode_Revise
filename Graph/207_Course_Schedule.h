#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prcount(numCourses, 0);
        vector<vector<int>> next(numCourses);

        for(int i = 0; i < prerequisites.size(); i++){
            prcount[prerequisites[i][0]]++;
            next[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(prcount[i] == 0)
                q.push(i);
        }

        int visited = 0;
        while(!q.empty()){
            visited++;
            int curr = q.front();
            q.pop();
            for(int node : next[curr]){
                if(--prcount[node] == 0)
                    q.push(node);
            }
        }
        return visited == numCourses;
    }
};