#include <vector>
#include <random>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) : data(nums), sz(nums.size()){}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return data; }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(data);
        for(int count = sz; count > 0; count--){
            swap(ret[count - 1], ret[rand() % count]);
        }
        return ret;
    }

private:
    vector<int> data;
    int sz;
};