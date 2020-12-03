#include <vector>
#include <unordered_map>
#include <random>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.find(val) == index.end()){
            index[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.find(val) != index.end()){
            int i = index[val];
            index[nums.back()] = i;
            nums[i] = nums.back();
            index.erase(val);
            nums.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    unordered_map<int, int> index;
    vector<int> nums;
};