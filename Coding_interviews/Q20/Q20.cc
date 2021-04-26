#include <iostream>
#include <unordered_map>
#include <string.h>

class Solution {
public:
    enum State {
        STATE_BEGIN,
        STATE_SIGN1,
        STATE_INTEGER,
        STATE_DOT1, // nums.(nums)
        STATE_DOT2, // .nums
        STATE_FRACTION,
        STATE_EXPONENT,
        STATE_SIGN2,
        STATE_EXPNUM,
        STATE_END
    };

    enum Input {
        INPUT_BLANK,
        INPUT_SIGN,
        INPUT_INTEGER,
        INPUT_DOT,
        INPUT_EXPONENT,
        INPUT_ILLEGAL
    };

    Input toInput(char ch) {
        if (ch == ' ') {return INPUT_BLANK;}
        else if (ch == '+' || ch == '-') {return INPUT_SIGN;}
        else if (ch == '.') {return INPUT_DOT;}
        else if (ch <= '9' && ch >= '0') {return INPUT_INTEGER;}
        else if (ch == 'e' || ch == 'E') {return INPUT_EXPONENT;}
        else {return INPUT_ILLEGAL;}
    }

    bool isNumeric(std::string str) {
        if (str.empty()) {return false;}
        State curState = STATE_BEGIN;
        std::unordered_map<State, std::unordered_map<Input, State>> transform {
            {
                STATE_BEGIN, {
                    {INPUT_BLANK, STATE_BEGIN},
                    {INPUT_SIGN, STATE_SIGN1},
                    {INPUT_DOT, STATE_DOT2},
                    {INPUT_INTEGER, STATE_INTEGER}
                }
            }, {
                STATE_SIGN1, {
                    {INPUT_DOT, STATE_DOT2},
                    {INPUT_INTEGER, STATE_INTEGER}
                }
            }, {
                STATE_INTEGER, {
                    {INPUT_INTEGER, STATE_INTEGER},
                    {INPUT_DOT, STATE_DOT1},
                    {INPUT_EXPONENT, STATE_EXPONENT},
                    {INPUT_BLANK, STATE_END}
                }
            }, {
                STATE_DOT1, {
                    {INPUT_INTEGER, STATE_FRACTION},
                    {INPUT_EXPONENT, STATE_EXPONENT},
                    {INPUT_BLANK, STATE_END}
                }
            }, {
                STATE_DOT2, {
                    {INPUT_INTEGER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION, {
                    {INPUT_INTEGER, STATE_FRACTION},
                    {INPUT_EXPONENT, STATE_EXPONENT},
                    {INPUT_BLANK, STATE_END}
                }
            }, {
                STATE_EXPONENT, {
                    {INPUT_SIGN, STATE_SIGN2},
                    {INPUT_INTEGER, STATE_EXPNUM}
                }
            }, {
                STATE_SIGN2, {
                    {INPUT_INTEGER, STATE_EXPNUM}
                }
            }, {
                STATE_EXPNUM, {
                    {INPUT_INTEGER, STATE_EXPNUM},
                    {INPUT_BLANK, STATE_END}
                }
            }, {
                STATE_END, {
                    {INPUT_BLANK, STATE_END}
                }
            }
        };
        
        for (char& ch : str) {
            Input ipt = toInput(ch);
            if (transform[curState].find(ipt) == transform[curState].end()) {return false;}
            else {
                curState = transform[curState][ipt];
            }
        }

        return curState == STATE_INTEGER || curState == STATE_FRACTION 
            || curState == STATE_END || curState == STATE_DOT1 || curState == STATE_EXPNUM;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    std::string test1("-3.1415926e7");
    if (s.isNumeric(test1)) {printf("is numeric!\n");}
    else {printf("is NOT numeric\n");}
    return 0;
}