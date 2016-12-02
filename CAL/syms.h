
// Created by emman on 2016/11/25.
//

#ifndef OOP_SYMS_H
#define OOP_SYMS_H

#include <map>
#include <string>

using namespace std;
enum Token_value {
    NAME,
    NUMBER,
    END,
    PLUS = '+',
    MINUS = '-',
    MUL = '*',
    DIV = '/',
    PRINT = ';',
    ASSIGN = '=',
    LP = '(',
    RP = ')'
};

extern Token_value curr_tok;
extern double number_value;
extern string string_value;
extern map<string, double> mtable;
extern int no_of_errors;
extern int curr_line;


#endif //OOP_SYMS_H
