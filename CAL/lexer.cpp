//
// Created by emman on 2016/11/25.
//

# include <iostream>
# include "error.h"

using namespace std;


Token_value get_token() {
    char ch = 0;
    cin >> ch;
    switch (ch) {
        case 0:
            return curr_tok = END;
        case ';':
        case '*': case '/':
        case '+':
        case '-': case '(':
        case ')': case '=':
            return curr_tok = Token_value(ch);
        case '1':
        case '2': case '3':
        case '4': case '5':
        case '6': case '7':
        case '8': case '9':
        case '0': case '.':
            cin.putback(ch);
            cin >> number_value;
            return curr_tok = NUMBER;
        default:
            if (isalpha(ch)) {
                cin.putback(ch);
                cin >> string_value;
                return curr_tok = NAME;
            }
            error("bad token");
            return curr_tok = PRINT;
    }
}
