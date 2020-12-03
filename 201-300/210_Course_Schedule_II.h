#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        vector<int> ret;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                ret.push_back(i);
        }

        for(int i = 0; i < ret.size(); i++){
            for(int next : adj[ret[i]]){
                if(--indegree[next] == 0)
                    ret.push_back(next);
            }
        }

        if(ret.size() != numCourses) return {};

        return ret;
    }
};