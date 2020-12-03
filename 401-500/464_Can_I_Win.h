#include <vector>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        this->candidates = maxChoosableInteger;
        vector<int> memo(1 << maxChoosableInteger, -1);
        return recurse(memo, (1 << maxChoosableInteger) - 1, desiredTotal);
    }

private:
    int candidates;
    bool recurse(vector<int>& memo, int currstate, int target){
        if(memo[currstate] != -1){
            return memo[currstate] == 1;
        }

        memo[currstate] = 0;
        for(int i = 0; i < candidates; i++){
            if((currstate & (1 << i))){
                if(i + 1 >= target){
                    memo[currstate] = 1;
                    break;
                }

                if(!recurse(memo, currstate ^ (1 << i), target - i - 1)){
                    memo[currstate] = 1;
                    break;
                }
            }
        }

        return memo[currstate] == 1;
    }
};