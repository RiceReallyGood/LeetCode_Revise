#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        wordList.push_back(beginWord);
        int n = wordList.size();
        unordered_map<string, int> wordindex;
        for(int i = 0; i < n; i++){
            wordindex[wordList[i]] = i;
        }
        if(wordindex.find(endWord) == wordindex.end())
            return ret;
        int bid = wordindex[beginWord];
        int eid = wordindex[endWord];

        vector<vector<int>> nextsteps(n);
        unordered_set<int> beginset, endset;
        beginset.insert(wordindex[beginWord]);
        endset.insert(wordindex[endWord]);
        bool swaped = false;
        vector<bool> visited(n, false);

        bool LadderFound = false;
        int wl = beginWord.length();
        while(!LadderFound && !beginset.empty() && !endset.empty()){
            if(endset.size() < beginset.size()){
                swap(beginset, endset);
                swaped = !swaped;
            }
            for(int id : beginset)
                visited[id] = true;
            unordered_set<int> nextlevel;
            for(int id : beginset){
                string trialword = wordList[id];
                for(int i = 0; i < wl; i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == wordList[id][i]) continue;
                        trialword[i] = c;
                        if(wordindex.find(trialword) != wordindex.end()){
                            int nextid = wordindex[trialword];
                            if(visited[nextid]) continue;
                            if(endset.find(nextid) != endset.end())
                                LadderFound = true;
                            if(swaped){
                                nextsteps[nextid].push_back(id);
                            }
                            else{
                                nextsteps[id].push_back(nextid);
                            }
                            nextlevel.insert(nextid);
                        }
                    }
                    trialword[i] = wordList[id][i];
                }
            }
            swap(beginset, nextlevel);
        }

        if(LadderFound){
            vector<int> path;
            ExtractLadder(wordList, nextsteps, bid, eid, path, ret);
        }
        return ret;
    }

private:
    void ExtractLadder(vector<string>& wordList, vector<vector<int>>& nextsteps, 
            int bid, int eid, vector<int>& path, vector<vector<string>>& ret){
        path.push_back(bid);
        if(bid == eid){
            ret.push_back(vector<string>());
            for(int i = 0; i < path.size(); i++)
                ret.back().push_back(wordList[path[i]]);
        }
        else{
            for(int nextid : nextsteps[bid]){
                ExtractLadder(wordList, nextsteps, nextid, eid, path, ret);
            }
        }
        path.pop_back();
    }
};