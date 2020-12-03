#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) : king(kingName){
        isalive[kingName] = true;
    }
    
    void birth(string parentName, string childName) {
        m[parentName].push_back(childName);
        isalive[childName] = true;
    }
    
    void death(string name) {
        isalive[name] = false;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(king, res);
        return res;
    }

private:
    string king;
    unordered_map<string, vector<string>> m;
    unordered_map<string, bool> isalive;

    void dfs(string& name, vector<string>& res){
        if(isalive[name]){
            res.push_back(name);
        }

        for(string& child : m[name]){
            dfs(child, res);
        }
    }
};