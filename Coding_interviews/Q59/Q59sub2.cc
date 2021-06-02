#include <iostream>
#include <queue>
#include <deque>

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (dq.empty()) {return -1;}
        return dq.front();
    }
    
    void push_back(int value) {
        while (!dq.empty() && value > dq.back()) {dq.pop_back();}
        dq.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty()) {return -1;}
        if (dq.front() == q.front()) {dq.pop_front();}
        int popValue = q.front();
        q.pop();
        return popValue;
    }
private:
    std::queue<int> q;
    std::deque<int> dq;
};

int main(int argc, const char** argv) {
    MaxQueue mq;
    // pop_front() or max_value when MaxQueue is empty
    // push_back repeated number
    // normal test
    mq.push_back(2);
    mq.push_back(1);
    mq.push_back(2);
    int mVal1 = mq.max_value();
    mq.pop_front();
    int mVal2 = mq.max_value();
    mq.pop_front();
    int mVal3 = mq.max_value();
    mq.pop_front();
    int mVal4 = mq.max_value();
    printf("%d\n", mVal1);
    printf("%d\n", mVal2);
    printf("%d\n", mVal3);
    printf("%d\n", mVal4);
    return 0;
}
