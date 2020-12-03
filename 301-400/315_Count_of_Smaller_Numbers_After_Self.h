#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        this->n = nums.size();
        vector<pair<int, int>> num_index;
        for(int i = 0; i < n; i++)
            num_index.emplace_back(make_pair(nums[i], i));
        sort(num_index.begin(), num_index.end());

        bit = vector<int>(n + 1, 0);

        vector<int> ret(n);
        for(int i = 0; i < n; i++){
            int idx = num_index[i].second;
            ret[idx] = i - PrefixSum(idx);
            add(idx + 1, 1);
        }
        return ret;
    }

private:
    int n;
    vector<int> bit;

    int PrefixSum(int idx){
        int ret = 0;
        for(int i = idx; i; i -= (i & (-i)))
            ret += bit[i];
        return ret;
    }

    void add(int idx, int val){
        for(int i = idx; i <= n; i += (i & (-i)))
            bit[i] += val;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        index.resize(n);
        aux.resize(n);
        count.resize(n);
        for(int i = 0; i < n; i++) index[i] = i;
        MergeSort(nums, 0, n - 1);
        return count;
    }

private:
    vector<int> index;
    vector<int> aux;
    vector<int> count;
    void MergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int c = l + (r - l) / 2;
        MergeSort(nums, l, c);
        MergeSort(nums, c + 1, r);

        int i = l, j = c + 1;
        for(int k = l; k <= r; k++){
            if(i > c){
                aux[k] = index[j++];
            }
            else if(j > r){
                aux[k] = index[i++];
                count[aux[k]] += j - c - 1;
            }
            else if(nums[index[i]] <= nums[index[j]]){
                aux[k] = index[i++];
                count[aux[k]] += j - c - 1;
            }
            else{
                aux[k] = index[j++];
            }
        }

        for(int i = l; i <= r; i++)
            index[i] = aux[i];
    }
};