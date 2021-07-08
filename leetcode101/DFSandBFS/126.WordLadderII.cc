#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using WordList = std::vector<std::string>;

class Solution {
public:
    void getNeighbors(const std::string& str,
                      std::unordered_map<std::string, WordList>& hashMap,
                      const WordList& wordList,
                      std::unordered_set<std::string>& st) {
        if (st.count(str)) {st.erase(str);}
        std::string change = str;
        for (int i = 0; i < change.size(); ++i) {
            change = str;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                change[i] = ch;
                if (st.find(change) != st.end()) {hashMap[str].push_back(change);}
            }
        }
        st.emplace(str);
    }

    std::vector<WordList> findLadders(std::string beginWord,
                                      std::string endWord,
                                      WordList& wordList) {
        if (wordList.empty()) {return {};}
        std::vector<WordList> res;
        std::unordered_map<std::string, WordList> hashMap;
        std::unordered_set<std::string> st;
        for (const std::string& str : wordList) {st.emplace(str);}
        if (st.find(endWord) == st.end()) {return res;}

        std::queue<WordList> q;
        WordList current;
        WordList needAdd;
        int size = 0;
        std::unordered_set<std::string> visited;
        std::unordered_set<std::string> subVisited;
        visited.emplace(beginWord);
        bool endFlag = false;
        q.push({beginWord});
        while (!q.empty()) {
            size = q.size();
            subVisited.clear();
            while (size--) {
                current = q.front();
                q.pop();
                getNeighbors(current.back(), hashMap, wordList, st);
                for (const std::string& str : hashMap[current.back()]) {
                    if (visited.find(str) == visited.end()) {
                        subVisited.emplace(str);
                        needAdd = current;
                        needAdd.push_back(str);
                        q.push(needAdd);
                    }
                    if (str == endWord) {
                        endFlag = true;
                        res.push_back(needAdd);    
                    }
                }
                hashMap[current.back()].clear();
            }
            for (const std::string& str : subVisited) {visited.emplace(str);}
            if (endFlag) {break;}
        }

        return res;
    }
};

// int main(int argc, const char** argv) {
//     std::unordered_map<int, WordList> hashMap;
//     hashMap[0].push_back({"abc"});
//     hashMap[0].push_back({"abc"});
//     for (const std::string& str : hashMap[0]) {
//         printf("%s\n", str.c_str());
//     }
//     return 0;
// }