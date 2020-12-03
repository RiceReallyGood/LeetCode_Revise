#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution { //208ms
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(string& s : strs){
            int count[26] = {0};
            for(char c: s)
                count[c - 'a']++;
            string key;
            for(int i = 0; i < 26; i++){
                key += to_string(count[i]);
                key.push_back('#');
            }
            res[key].push_back(s);
        }

        vector<vector<string>> ret;
        for (auto& pair : res)
            ret.push_back(pair.second);
        return ret;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,int> index;
        int sz = 0;
        for(string &s : strs){
            string s1 = s;
            sort(s1.begin(), s1.end());
            if(index.find(s1) != index.end()){
                res[index[s1]].push_back(s);
            }
            else{
                index[s1] = sz++;
                res.push_back({ s });
            }
        }
        return res;
    }
};