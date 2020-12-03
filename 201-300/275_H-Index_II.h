#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        int l = 0, r = n + 1;

        while(l < r){
            int c = l + (r - l) / 2;
            if(citations[c] < n - c)
                l = c + 1;
            else
                r = c;
        }
        return n - l;
    }
};