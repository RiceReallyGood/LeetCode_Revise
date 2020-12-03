#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);

        for(int i = 0; i < n; i++){
            if(citations[i] <= n)
                count[citations[i]]++;
        }

        int hidx = 0, ge = n;

        while(hidx <= ge){
            ge -= count[hidx];
            hidx++;
        }

        return --hidx;
    }
};