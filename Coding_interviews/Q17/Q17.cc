#include <iostream>
#include <string.h>

class Solution {
public:
    void printNumber(const std::string& numbers) {
        std::string::const_iterator it = numbers.begin();
        while (*it == '0') {it++;}
        while (it != numbers.end()) {
            printf("%c", *it);
            it++;
        }
        printf("\t");
    }

    bool Increment(std::string& numbers) {
        int length = numbers.size();
        int isOverFlow = false;
        int carry = 0;
        int tmpSum = 0;
        for (int i = length - 1; i >= 0; i--) {
            tmpSum = numbers[i] - '0' + carry;
            if (i == length - 1) {tmpSum++;}
            if (tmpSum >= 10) {
                if (i == 0) {
                    isOverFlow = true;
                    break;
                }
                else {
                    carry = 1;
                    numbers[i] = '0';
                }
            }
            else {
                numbers[i] = '0' + tmpSum;
                break;
            }
        }
        return isOverFlow;
    }

    void print1toMaxofNDigits_solution1(int n) {
        if (n <= 0) {
            printf("Invalid Input!");
            return;
        }
        std::string numbers(n, '0');
        while (!Increment(numbers)) {
            printNumber(numbers);
        }
    }

    void print1toMaxofNDigits_solution2(int n) {
        if (n <= 0) {
            printf("Invalid Input!");
            return;
        }
        std::string numbers(n, '0');
        print1toMaxofNDigitsRecursively(numbers, n, 0);
    }

    //theDigit : print from "the digit"
    void print1toMaxofNDigitsRecursively(std::string& numbers, int length, int theDigit) {
        if (theDigit == length) {
            printNumber(numbers);
            return;
        }
        for (int i = 0; i < 10; i++) {
            numbers[theDigit] = '0' + i;
            print1toMaxofNDigitsRecursively(numbers, length, theDigit + 1);
        }
    }
};

int main(int argc, const char** argv) {
    Solution s;
    s.print1toMaxofNDigits_solution2(3);
    printf("\n");
    return 0;
}