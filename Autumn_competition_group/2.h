#include <vector>
using namespace std;

class Solution {
public:
    bool isMagic(vector<int>& target) {
        int n = target.size();
        if(n == 1) return true;
        int k = findk(n, target);
        if(k == 0) return false;
        return check(k, target);
    }

private:
    int findk(int n, vector<int>& target){
        int count = 0, num = 2;
        while(count < n){
            if(num > n) num = 1;
            if(target[count] != num)
                break;
            count++;
            num += 2;
        }
        return count;
    }
    
    bool check(int k, vector<int>& target){
        int n = target.size();
        vector<int> arr(n), temp(n);
        for(int i = 0; i < n; i++)
            arr[i] = i + 1;
        
        int start = 0;
        while(start < n){
            temp = arr;
            int index = start + 1;
            for(int count = 0; count < n - start; count++){
                if(index >= n) index = start;
                arr[count + start] = temp[index];
                index += 2;
            }

            for(int i = 0; i < k && start + i < n; i++){
                if(arr[start + i] != target[start + i])
                    return false;
            }

            start += k;
        }
        return true;
    }
};