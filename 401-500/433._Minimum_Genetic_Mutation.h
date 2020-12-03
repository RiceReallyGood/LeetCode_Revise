#include <string>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <queue>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int b = toInt(start), e = toInt(end);
        unordered_set<int> beginset = {b};
        unordered_set<int> endset = {e};
        unordered_set<int> bankset;
        for(int i = 0; i < bank.size(); i++){
            bankset.insert(toInt(bank[i]));
        }
        if(bankset.find(e) == bankset.end())
            return -1;
        bankset.erase(b);

        int level = 0;
        while(!beginset.empty() && !endset.empty()){
            if(beginset.size() > endset.size())
                beginset.swap(endset);
            level++;
            
            unordered_set<int> nextlevel;
            for(int num : beginset){
                for(int i = 1; i < 4; i++){
                    for(int shift = 0; shift < 16; shift += 2){
                        int mutation = num ^ (i << shift);
                        if(endset.find(mutation) != endset.end())
                            return level;
                        
                        if(bankset.find(mutation) != bankset.end()){
                            bankset.erase(mutation);
                            nextlevel.insert(mutation);
                        }
                    }
                }
            }

            beginset.swap(nextlevel);
        }
        return -1;
    }

private:
    int toInt(const string& s){
        int res = 0;
        for(int i = 0; i < 8; i++){
            int curr_n = 0;
            if(s[i] == 'A') curr_n = 0;
            else if(s[i] == 'C') curr_n = 1;
            else if(s[i] == 'G') curr_n = 2;
            else curr_n = 3;
            res = (res << 2) | curr_n;
        }
        return res;
    }
};

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        bitset<1 << 16> bankset;
        int target = encode(end);
        for(int i = 0; i < bank.size(); i++)
            bankset.set(encode(bank[i]));
        if(!bankset[target]) return -1;
        queue<int> q;
        q.push(encode(start));
        int level = 0;
        while(!q.empty()){
            level++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int curr = q.front();
                q.pop();
                for(int c = 1; c < 4; c++){
                    for(int shift = 0; shift < 16; shift += 2){
                        int mutation = curr ^ (c << shift);
                        if(mutation == target)
                            return level;
                        
                        if(bankset[mutation]){
                            bankset.reset(mutation);
                            q.push(mutation);
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    int encode(string& s){
        static vector<int> toint = { 0, -1,  1, -1, -1, -1,  2, -1, -1, -1, -1, -1, -1,
                                    -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1};
        int ret = 0;
        for(int i = 0; i < 8; i++)
            ret = (ret << 2) | toint[s[i] - 'A'];
        return ret;
    }
};