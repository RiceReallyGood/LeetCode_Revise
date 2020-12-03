#include <vector>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};

        int slen = s.length(), wlen = words[0].length();
        unordered_map<string, int> wordindex;
        vector<int> wordcount;
        int sz = 0;
        for(int i = 0; i < words.size(); i++){
            if(wordindex.find(words[i]) != wordindex.end())
                wordcount[wordindex[words[i]]]++;
            else{
                wordindex[words[i]] = sz;
                swap(words[sz], words[i]);
                wordcount.push_back(1);
                sz++;
            }
        }
        
        vector<int> match(slen, -1);
        vector<int> prefix(wlen);
        vector<int> ret;

        //preprocess
        for(int i = 0; i < sz; i++){
            string word = words[i];
            for(int j = 1, k = 0; j < wlen; j++){
                while(k != 0 && word[j] != word[k])
                    k = prefix[k - 1];
                if(word[j] == word[k])
                    k++;
                prefix[j] = k;
            }

            for(int j = 0, k = 0; j < slen; j++){
                while(k != 0 && s[j] != word[k])
                    k = prefix[k - 1];
                if(s[j] == word[k])
                    k++;
                if(k == wlen){
                    match[j - wlen + 1] = i;
                    k = prefix[wlen - 1];
                }
            }
        }

        //two pointer
        for(int shift = 0; shift < wlen; shift++){
            int i = shift;
            for(int j = shift; j < slen; j += wlen){
                if(match[j] != -1 && wordcount[match[j]] > 0){
                    wordcount[match[j]]--;
                }
                else{
                    while(match[i] != match[j]){
                        wordcount[match[i]]++;
                        i += wlen;
                    }
                    i += wlen;
                }
                if(j - i == (words.size() - 1) * wlen)
                    ret.push_back(i);
            }
            while(i < slen){
                wordcount[match[i]]++;
                i += wlen;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};

        int slen = s.length(), wlen = words[0].length();
        unordered_map<string, int> wordcount;
        for(auto& word : words)
            wordcount[word]++;

        vector<int> ret;
        for(int shift = 0; shift < wlen; shift++){
            int left = shift, right = shift;
            while(right <= slen - wlen){
                string subs = s.substr(right, wlen);
                if(wordcount.find(subs) != wordcount.end()){
                    while(wordcount[subs] == 0){
                        wordcount[s.substr(left, wlen)]++;
                        left += wlen;
                    }
                    wordcount[subs]--;
                    if(right - left == (words.size() - 1) * wlen)
                        ret.push_back(left);
                }
                else{
                    while(left < right){
                        wordcount[s.substr(left, wlen)]++;
                        left += wlen;
                    }
                    left += wlen;
                }
                right += wlen;
            }
            while(left < right){
                wordcount[s.substr(left, wlen)]++;
                left += wlen;
            }
        }
        return ret;
    }
};