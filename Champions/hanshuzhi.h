#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

class segementTree{
public:
    segementTree(vector<int>& input) : data(input), n(input.size()),tree(n * 4){
        BuildTree(0, 0, n - 1);
    }

    int query(int queryL, int queryR){
        return __query(0, 0, n - 1, queryL, queryR);
    }

private:
    int n;
    vector<int> data;
    vector<int> tree;

    int leftchild(int index) { return 2 * index + 1; }
    int rightchild(int index) { return 2 * index + 2; }

    void BuildTree(int treeindex, int l, int r){
        if(l == r){
            tree[treeindex] = data[l];
            return;
        }

        int lefttreeindex = leftchild(treeindex);
        int righttreeindex = rightchild(treeindex);

        int c = l + (r - l) / 2;

        BuildTree(lefttreeindex, l, c);
        BuildTree(righttreeindex, c + 1, r);

        tree[treeindex] = tree[lefttreeindex] & tree[righttreeindex];
    }

    int __query(int treeIndex, int l, int r, int queryL, int queryR){
        if(l == queryL && r == queryR)
            return tree[treeIndex];
        
        int mid = l + (r - l) / 2;
        // treeIndex的节点分为[l...mid]和[mid+1...r]两部分

        int leftTreeIndex = leftchild(treeIndex);
        int rightTreeIndex = rightchild(treeIndex);
        if(queryL >= mid + 1)
            return __query(rightTreeIndex, mid + 1, r, queryL, queryR);
        else if(queryR <= mid)
            return __query(leftTreeIndex, l, mid, queryL, queryR);

        int leftResult = __query(leftTreeIndex, l, mid, queryL, mid);
        int rightResult = __query(rightTreeIndex, mid + 1, r, mid + 1, queryR);
        return leftResult & rightResult;
    }
};



class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != arr[i - 1]){
                arr[n++] = arr[i];
            }
        }
        long ret = INT_MAX;
        segementTree st(arr);
        for(int i = 0; i < n; i++){
            int l = 0, r = i + 1;
            while(l < r){
                int c = l + (r - l) / 2;
                if(st.query(c, i) <= target)
                    l = c + 1;
                else
                    r = c;
            }

            if(l <= i) ret = min(ret, long(st.query(l, i)) - long(target));
            if(l > 0) ret = min(ret, long(target) - long(st.query(l - 1, i)));
        }

        ret = min(ret, abs(long(target) - 1000000000L));

        return ret;
    }
};

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != arr[i - 1]){
                arr[n++] = arr[i];
            }
        }

        int diff = INT_MAX;
        for(int i = 0; i < n; i ++){
            int res = arr[i];
            diff = min(diff, abs(res - target));
            for(int j = i + 1; j < n; j ++){
                res &= arr[j];
                int newdiff = abs(res - target);
                if(newdiff >= diff) break;
                diff = newdiff;
            }
        }
        return diff;
    }
};