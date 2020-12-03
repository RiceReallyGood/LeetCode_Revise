#include <vector>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0;

        int heiindex = 0, temp = n;
        while(temp){
            heiindex++;
            temp >>= 1;
        }
        return change(n, heiindex - 1, 0);
    }

private:
    int change(int num, int index, int digit){
        if(index == 0){
            return (num & 1) ^ digit;
        }

        if((num >> index & 1) == digit){
            return change(num, index - 1, 0);
        }
        else{
            return change(num, index - 1, 1) + (1 << index);
        }
    }
};