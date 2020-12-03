#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset;
        for(auto& word : wordList)
            wordset.insert(word);
        if(wordset.find(endWord) == wordset.end()) return 0;
        wordset.erase(endWord);
        unordered_set<string> beginset, endset;
        beginset.insert(beginWord);
        endset.insert(endWord);
        int step = 0;

        while(!beginset.empty() && !endset.empty()){
            step++;
            if(endset.size() > beginset.size())
                swap(beginset, endset);
            
            unordered_set<string> tempset;
            for(auto& word : beginset){
                string temp = word;
                for(int i = 0; i < word.length(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == word[i]) continue;
                        temp[i] = c;
                        if(endset.find(temp) != endset.end())
                            return step;
                        if(wordset.find(temp) != wordset.end()){
                            tempset.insert(temp);
                            wordset.erase(temp);
                        }
                    }
                    temp[i] = word[i];
                }
            }
            swap(beginset, tempset);
        }
        return 0;
    }
};