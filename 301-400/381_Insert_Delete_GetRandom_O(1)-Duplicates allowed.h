#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(indices.find(val) == indices.end()){
            indices[val] = {static_cast<int>(nums.size())};
            nums.push_back(val);
            return true;
        }
        else{
            indices[val].insert(static_cast<int>(nums.size()));
            nums.push_back(val);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(indices.find(val) == indices.end()) return false;

        int i = *(indices[val].begin());

        
        indices[val].erase(i);
        if(i != nums.size() - 1){
            indices[nums.back()].erase(nums.size() - 1);
            indices[nums.back()].insert(i);
            nums[i] = nums.back();
        }
        
        nums.pop_back();

        if(indices[val].empty())
            indices.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() { return nums[rand() % nums.size()]; }

private:
    unordered_map<int, unordered_set<int>> indices;
    vector<int> nums;
};