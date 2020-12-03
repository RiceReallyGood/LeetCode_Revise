#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string ret;
        for(int i = 0; i < strs[0].length(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(i == strs[j].length() || strs[j][i] != strs[0][i])
                    return ret;
            }
            ret.push_back(strs[0][i]);
        }
        return ret;
    }
};