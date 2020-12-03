#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        int index = 0, len = path.length();
        while(index < len){
            while(index < len && path[index] == '/') index++;
            if(index == len) break;
            string name;
            while(index < len && path[index] != '/')
                name.push_back(path[index++]);
            if(name == ".") continue;
            if(name == ".."){
                while(!ret.empty() && ret.back() != '/')
                    ret.pop_back();
                if(!ret.empty()) ret.pop_back();
            }
            else{
                ret += "/" + name;
            }
        }
        if(ret.empty()) ret.push_back('/');
        return ret;
    }
};