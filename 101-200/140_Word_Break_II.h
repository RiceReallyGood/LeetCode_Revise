#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        if(!CanBreak(s, wordset)) return {};
        vector<string> res;
        string partitions;
        backtrace(s, 0, partitions, wordset, res);
        return res;
    }

private:
    bool CanBreak(string& s, unordered_set<string>& wordset) {
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int i = 0; i < len; i++){
            for(int j = i; j >= 0; j--){
                if(dp[j] && wordset.find(s.substr(j, i - j + 1)) != wordset.end()){
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[len];
    }

    void backtrace(string& s, int index, string& partitions, unordered_set<string>& wordset, vector<string>& res){
        if(index == s.length()){
            partitions.pop_back();
            res.emplace_back(partitions);
            partitions.push_back(' ');
            return;
        }

        for(int j = index; j < s.length(); j++){
            partitions.push_back(s[j]);
            if(wordset.find(s.substr(index, j - index + 1)) != wordset.end()){
                partitions.push_back(' ');
                backtrace(s, j + 1, partitions, wordset, res);
                partitions.pop_back();
            }
        }
        for(int i = 0; i < s.length() - index; i++)
            partitions.pop_back();
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        int wordmaxlen = 0;
        for(auto& word : wordDict)
            wordmaxlen = max(wordmaxlen, int(word.length()));
        int slen = s.length();
        vector<bool> Canbreak(slen + 1);
        Canbreak[0] = true;
        vector<vector<int>> next(slen);
        for(int i = 0; i < slen; i++){
            for(int j = i + 1; j - i <= wordmaxlen && j <= slen; j++){
                if(wordset.find(s.substr(i, j - i)) != wordset.end()){
                    next[i].push_back(j);
                    if(Canbreak[i]) Canbreak[j] = true;
                }
            }
        }
        if(!Canbreak[slen]) return {};
        vector<string> res;
        string sentence;
        GenerateSentences(s, 0, sentence, next, res);
        return res;
    }

private:
    void GenerateSentences(string& s, int index, string& sentence,vector<vector<int>>& next, vector<string>& res){
        if(index == s.length()){
            sentence.pop_back();
            res.emplace_back(sentence);
            sentence.push_back(' ');
            return;
        }

        for(int nextindex : next[index]){
            while(index < nextindex) sentence.push_back(s[index++]);
            sentence.push_back(' ');
            GenerateSentences(s, nextindex, sentence, next, res);
            sentence.pop_back();
        }

        while(!sentence.empty() && sentence.back() != ' ')
            sentence.pop_back();
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> breaks(s.length() + 1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        if(!CanBreak(s, wordSet)) return {};
        int maxlen = 0;
        for(int i = 0; i < wordDict.size(); i++)
            maxlen = max(maxlen, int(wordDict[i].length()));

        for(int len = 1; len <= maxlen && len <= s.length(); len++)
            if(wordSet.find(s.substr(0, len)) != wordSet.end())
                breaks[len].push_back(s.substr(0, len));
        
        for(int i = 1; i < s.length(); i++){
            if(breaks[i].empty())
                continue;
            for(int len = 1; len <= maxlen && i + len <= s.length(); len++){
                string sub = s.substr(i, len);
                if(wordSet.find(sub) != wordSet.end()){
                    for(string br : breaks[i])
                        breaks[i + len].push_back(br + " " + sub);
                }
            }
        }
        return breaks[s.length()];
    }

private:
    bool CanBreak(string& s, unordered_set<string>& wordset) {
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int i = 0; i < len; i++){
            for(int j = i; j >= 0; j--){
                if(dp[j] && wordset.find(s.substr(j, i - j + 1)) != wordset.end()){
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};