#include <iostream>
#include <stack>

template<class T>
class myQueue {
public:
    void push(const T& val) {
        stk2.push(val);
    }

    T pop() {
        T res;
        if (stk1.empty()) {
            if (stk2.empty()) {
                printf("The queue is empty. Please do not pop again");
                return 0;
            }
            while (!stk2.empty()) {
                stk1.push(stk2.top());
                stk2.pop();
            }

        }
        res = stk1.top();
        stk1.pop();
        return res;
    }

private:
    std::stack<T> stk1; //main
    std::stack<T> stk2; //accessory
};

int main(int argc, const char** argv) {
    myQueue<int> q;
    q.push(1);
    q.push(2);
    //q.pop();
    printf("%d\n", q.pop());
    q.push(3);
    q.push(4);
    printf("%d\n", q.pop());
    q.push(5);
    q.push(6);
    printf("%d\n", q.pop());
    printf("%d\n", q.pop());
    printf("%d\n", q.pop());
    printf("%d\n", q.pop());
    printf("%d\n", q.pop());
    printf("%d\n", q.pop());
    return 0;
}