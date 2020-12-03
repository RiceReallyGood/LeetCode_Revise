#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.length();
        if(k >= n * (n - 1) / 2){
            sort(num.begin(), num.end());
            return num;
        }
        int index = 0;
        while(k > 0 && index < num.length()){
            int minindex = index;
            for(int i = index; i < num.length() && i - index <= k; i++){
                if(num[i] < num[minindex]) minindex = i;
            }
            if(minindex == index){
                index++;
                continue;
            }
            else{
                char temp = num[minindex];
                for(int i = minindex; i > index; i--)
                    num[i] = num[i - 1];
                num[index] = temp;
                k -= (minindex - index);
                index++;
            }
        }
        return num;
    }
};


class Solution {
public:
    string minInteger(string num, int k) {
        n = num.length();

        count.resize(n + 1);
        for(int i = 0; i < n; i++) add(i + 1, 1);

        vector<vector<int>> digitindex(10);
        for(int i = n - 1; i >= 0; i--)
           digitindex[num[i] - '0'].push_back(i);
        
        string ret;
        for(int idx = 0; idx < n; idx++){
            for(int d = 0; d <= 9; d++){
                if(digitindex[d].empty())
                    continue;
                int pos = digitindex[d].back();
                int prevcount = sum(pos);
                if(prevcount > k) continue;
                k -= prevcount;
                digitindex[d].pop_back();
                ret.push_back(d + '0');
                add(pos + 1, -1);
                break;
            }
        }
        return ret;
    }

private:
    int n;
    vector<int> count;

    int sum(int idx){
        int ret = 0;
        for(int i = idx; i ; i -= (i & (-i)))
            ret += count[i];
        return ret;
    }

    void add(int idx, int val){
        for(int i = idx; i <= n; i += (i & (-i)))
            count[i] += val;
    }
};