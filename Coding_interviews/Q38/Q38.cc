#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> permutationString(std::string s) {
        if (s.empty()) {return res;}
        permutationCore(s, 0);
        std::sort(res.begin(), res.end());
        return res;
    }


private:
    // fix pre pos words and rotation after
    // cliche: standing on a normal point!
    void permutationCore(std::string s, int pos) {
        if (pos == s.size() - 1) {
            res.push_back(s);
            return;
        }
        std::set<char> st;
        for (int i = pos; i < s.size(); i++) {
            if (st.find(s[i]) != st.end()) {continue;}
            st.insert(s[i]);
            std::swap(s[i], s[pos]);
            permutationCore(s, pos + 1);
            std::swap(s[i], s[pos]);    //optional for this question, because of "arrangement"
        }
    }

    std::vector<std::string> res {};
};

int main(int argc, const char** argv) {
    Solution s;
    // empty
    // only one character
    // has repeated characters
    // normal
    std::string str {"abb"};
    std::vector<std::string> res = s.permutationString(str);
    printf("Permutations:\n");
    for (const std::string& strSub : res) {printf("%s ", strSub.c_str());}
    printf("\n");
    return 0;
}