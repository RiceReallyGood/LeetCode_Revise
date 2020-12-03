#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if(pq1.empty())
            pq1.push(num);
        else if(num >= pq1.top()){
            pq1.push(num);

            if(pq1.size() - pq2.size() == 2){
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
        else{
            pq2.push(num);

            if(pq2.size() > pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
    }
    
    double findMedian() {
        if(pq1.size() > pq2.size())
            return pq1.top();
        else
            return 0.5 * pq1.top() + 0.5 * pq2.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq1;
    std::priority_queue<int, std::vector<int>, std::less<int>> pq2;
};