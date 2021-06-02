#include <iostream>
#include <string.h>

class Solution {
public:
    void reverseString(std::string& str, int start, int end) {
        char temp = '\0';
        while (start <= end) {
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }

    // in this solution, we do not reverse extra blanks (p285)
    void reverseEnglishWords(std::string& str) {
        if (str.empty()) {
            printf("Input is empty!\n");
            return;
        }
        int start = 0;
        int end = str.size() - 1;
        reverseString(str, start, end);
        while (start < str.size()) {
            while (start < str.size() && str[start] == ' ') {start++;}
            end = start;
            while (end < str.size() && str[end] != ' ') {end++;}
            reverseString(str, start, end - 1);
            start = end;
        }
    }

    std::string reverseEnglishWords_removeSurplusBlanks(std::string& str) {
        std::string res {};
        if (str.empty()) {return res;}
        int right = str.size() - 1;
        int left = right;
        while (left >= 0) {
            while (right >= 0 && str[right] == ' ') {right--;}
            left = right;
            while (left >= 0 && str[left] != ' ') {left--;}
            // here, left >= 0 is wrong since in normal situation left finally should be -1
            if (right >= 0) {
                res += str.substr(left + 1, right - left);
                res += ' ';
            }
            right = left;
        }
        res.pop_back();
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // str.empty()
    // str contains only ' '
    // str.size() == 1, eg, str = {"I"};
    // str contains blanks at the begin/end of the string
    // str contains more than one blanks between words
    // str contains only one English word / more than one English words
    std::string str {"I am a student."};
    s.reverseEnglishWords(str);
    printf("After reversing, English words in string are:\n%s\n", str.c_str());
    return 0;
}