#include <iostream>
#include <stack>

template <class T>
class minStack {
public:
    void push(const T& val);
    void pop();
    T getMin();
    bool Equal (const T& val1, const T& val2);
    std::stack<T> stk_main;
    std::stack<T> stk_accessory;
};

template <class T> void minStack<T>::push(const T& val) {
    stk_main.push(val);
    if (stk_accessory.empty()) {stk_accessory.push(val);}
    else if (val <= stk_accessory.top()) {
        stk_accessory.push(val);        
    }
}

template <class T> void minStack<T>::pop() {
    if (stk_main.empty() || stk_accessory.empty()) {
        printf("The Stack is Empty!\n");
        return;
    }
    if (Equal(stk_accessory.top(), stk_main.top())) {
        stk_accessory.pop();
    }
    stk_main.pop();
}

template <class T>
bool minStack<T>::Equal(const T& val1, const T& val2) {
    if (val1 - val2 < 0.000000001 && val1 - val2 > -0.000000001) {return true;}
    return false;
}

template <class T> T minStack<T>::getMin() {
    if (stk_accessory.empty()) {
        printf("The Stack is Empty!\n");
        return -INT32_MAX;
    }
    return stk_accessory.top();
}

int main(int argc, const char** argv) {
    minStack<int> stk;
    stk.pop();
    stk.getMin();
    stk.push(4);
    stk.push(5);
    stk.push(2);
    stk.push(3);
    stk.push(1);
    int val = stk.getMin();
    printf("%d\n", val);
    stk.pop();
    stk.pop();
    val = stk.getMin();
    printf("%d\n", val);
    return 0;
}