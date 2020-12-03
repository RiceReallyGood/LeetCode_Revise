#include <vector>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int longest = 0;
        for(int i = 0; i < left.size(); i++)
            longest = max(longest, left[i]);
        for(int i = 0; i < right.size(); i++)
            longest = max(longest, n - right[i]);
        return longest;
    }
};