#include "iostream"
#include "string"

class Solution {
public:
    void ReplaceBlank(std::string& str) {
        if (str.empty()) {
            printf("Input string is empty");
            return;
        }
        int originalSize = str.size();
        int blankNums = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); it++) {
            if ((*it)==' ') {++blankNums;}
        }
        int newSize = originalSize + blankNums * 2;
        printf("newSize = %d\n", newSize);
        if (newSize > str.capacity()) {str.resize(newSize);}
        printf("Capacity = %ld\n", str.size());
        int index_org = originalSize;
        int index_new = newSize;
        while (index_org >= 0 && index_org < index_new) {
            if (str[index_org] != ' ') {
                str[index_new--] = str[index_org];
            }
            else {
                str[index_new--] = '0';
                str[index_new--] = '2';
                str[index_new--] = '%';
            }
            index_org--;
        }

    }
};

int main() {
    std::string str{" "};
    Solution s;
    s.ReplaceBlank(str);
    std::cout << str << std::endl;
    return 0;
}