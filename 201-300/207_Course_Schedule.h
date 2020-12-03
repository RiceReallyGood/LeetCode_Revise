#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        int count = 0;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            count++;
            for(int next: adj[c]){
                if(--indegree[next] == 0)
                    q.push(next);
            }
        }
        return count == numCourses;
    }
};