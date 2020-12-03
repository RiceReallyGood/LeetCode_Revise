#include <vector>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = x ^ y;
        int count = 0;
        while(dist){
            count++;
            dist = dist & (dist - 1);
        }
        return count;
    }
};