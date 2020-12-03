#ifndef BINARYINDEXTREE_H
#define BINARYINDEXTREE_H
#include <vector>

class BinaryIndexTree{
public:
    BinaryIndexTree(int n_) : n(n_), partialsum(n_ + 1) {}
    BinaryIndexTree(std::vector<int>& data) : n(data.size()), partialsum(data.size() + 1) {
        for(int i = 0; i < n; i++) add(i, data[i]);
    }

    void add(int i, int val){
        for(int idx = i + 1; i <= n; idx += (idx & (-idx))){
            partialsum[idx] += val;
        }
    }

    int sum(int i){
        int ret = 0;
        for(int idx = i + 1; idx > 0; idx -= (idx & (-idx))){
            ret += partialsum[idx];
        }
        return ret;
    }
private:
    int n;
    std::vector<int> partialsum;
};

#endif