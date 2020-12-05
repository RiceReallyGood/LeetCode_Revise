#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(int n_rows, int n_cols) : rows(n_rows), cols(n_cols), nz(n_rows * n_cols), indices(n_rows * n_cols) {
        for (int i = 0; i < nz; i++)
            indices[i] = i;
    }

    vector<int> flip() {
        swap(indices[nz - 1], indices[rand() % nz]);
        nz--;
        return {indices[nz] / cols, indices[nz] % cols};
    }

    void reset() {
        nz = rows * cols;
    }

private:
    int rows, cols, nz;
    vector<int> indices;
};

class Solution {
public:
    Solution(int n_rows, int n_cols) : rows(n_rows), cols(n_cols), nz(n_rows * n_cols) {}

    vector<int> flip() {
        int x = rand() % nz;
        int y = indices.find(x) == indices.end() ? x : indices[x];
        if (indices.find(nz - 1) != indices.end()) {
            indices[x] = indices[nz - 1];
            indices.erase(nz - 1);
        }
        else {
            indices[x] = nz - 1;
        }
        indices.erase(nz - 1);
        nz--;

        return {y / cols, y % cols};
    }

    void reset() {
        indices.clear();
        nz = rows * cols;
    }

private:
    int rows, cols, nz;
    unordered_map<int, int> indices;
};