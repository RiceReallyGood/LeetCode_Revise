#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int  sz = T.size();
        vector<int> ret(sz, 0);
        stack<int> S;
        for(int i = sz - 1; i >= 0; i--){
            while(!S.empty() && T[S.top()] <= T[i])
                S.pop();
            if(!S.empty())
                ret[i] = S.top() - i;
            S.push(i);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int  sz = T.size();
        vector<int> ret(sz, 0);
        stack<int> S;
        for(int i = 0; i < sz; i++){
            while(!S.empty() && T[S.top()] < T[i]){
                ret[S.top()] = i - S.top();
                S.pop();
            }
            S.push(i);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int  sz = T.size();
        vector<int> ret(sz, 0);
        for(int i = sz - 2; i >= 0; i--){
            int next = i + 1;
            while(next != 0 && T[next] <= T[i])
                next = ret[next];
            ret[i] = next;
        }
        for(int i = 0; i < sz; i++){
            if(ret[i] != 0) ret[i] -= i;
        }
        return ret;
    }
};