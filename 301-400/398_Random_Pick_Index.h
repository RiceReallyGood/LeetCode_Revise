#include <vector>
#include <random>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) :data(nums){}
    
    int pick(int target) {
        int count = 0;
        int ret = -1;
        for(int i = 0; i < data.size(); i++){
            if(data[i] == target){
                count++;
                if(rand() % count == 0)
                    ret = i;
            }
        }
        return ret;
    }

private:
    vector<int> data;
};