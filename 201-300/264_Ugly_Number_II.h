#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> un = {1};
        vector<int> p(3, 0);
        vector<int> factor = {2, 3, 5};
        vector<int> next = factor;

        while(un.size() < n){
            //find min position
            int pos = 0;
            for(int i = 0; i < 3; i++)
                if(next[i] < next[pos])
                    pos = i;

            if(next[pos] != un.back())
                un.push_back(next[pos]);
            
            p[pos]++;
            next[pos] = un[p[pos]] * factor[pos];
        }

        return un[n - 1];
    }
};