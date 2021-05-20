#include <iostream>
#include <queue>
#include <vector>

class medianFinder
{
public: 
    void addNum(int num) {
        int temp = INT32_MAX;
        if (maxHeap.size() == minHeap.size()) {
            minHeap.push(num);
            temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        else {
            maxHeap.push(num);
            temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
    }
    double findMedian() {
        if (maxHeap.empty()) {
            printf("The stream is empty!\n");
            return INT32_MAX / 1.0;
        }
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top() / 1.0;
    }
private:
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};

int main(int argc, const char** argv) {
    medianFinder mdf;
    // findMedian without any element
    // odd nums || even nums 
    // has repeated nums
    double res0 = mdf.findMedian();
    mdf.addNum(1);
    printf("%f\n", res0);
    double res1 = mdf.findMedian();
    mdf.addNum(2);
    printf("%f\n", res1);
    double res2 = mdf.findMedian();
    mdf.addNum(3);
    printf("%f\n", res2);
    double res3 = mdf.findMedian();
    mdf.addNum(2);
    printf("%f\n", res3);
    double res4 = mdf.findMedian();
    printf("%f\n", res4);
    return 0;
}