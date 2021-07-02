#include <iostream>
#include <vector>
#include <string.h>

using WordList = std::vector<std::string>;

class Solutio {
public:
    std::vector<WordList> findLadders(std::string beginWord,
                                      std::string endWord,
                                      WordList& wordList) {
        if (wordList.empty()) {return {};}
        
    }
};

int main(int argc, const char** argv) {
    std::vector<std::vector<int> > test;
    std::vector<int> testSample1 {1, 2};
    std::vector<int> testSample2 {1};
    test.push_back(testSample1);
    test.push_back(testSample2);
    for (auto it1 = test.begin(); it1 != test.end(); ++it1) {
        for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) {
            printf("%d ", *it2);
        }
        printf("\n");
    }
    return 0;
}