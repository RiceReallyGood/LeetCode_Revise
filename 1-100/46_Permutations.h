#include <vector>
using namespace std;


//Non lexicographic order
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        recurse(nums, 0, res);
        return res;
    }

private:
    void recurse(vector<int>& nums, int index, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            recurse(nums, index + 1, res);
            swap(nums[index], nums[i]);
        }
    }
};


//lexicographic order
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        recurse(nums, 0, res);
        return res;
    }

private:
    void recurse(vector<int>& nums, int index, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            recurse(nums, index + 1, res);
        }
        int temp = nums[index];
        for(int i = index; i < nums.size() - 1; i++)
            nums[i] = nums[i + 1];
        nums[nums.size() - 1] = temp;
    }
};