#include <vector>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int state = minutesToTest / minutesToDie + 1;

        int count = 0;
        buckets -= 1;
        while(buckets){
            buckets /= state;
            count++;
        }
        return count;
    }
};