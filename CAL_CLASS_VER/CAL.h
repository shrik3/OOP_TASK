//
// Created by shrik3 on 12/10/16.
//

#ifndef OOP_CAL_H
#define OOP_CAL_H

#include<iostream>
#include <cstdlib>
#include <fstream>
#include <map>

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

class CAL {
public:
    istream *input;

    void start();

    int no_of_errors = 0;
private:


    Token_value curr_tok;
    double number_value;
    string string_value;
    map<string, double> mtable;
    int curr_line = 1;
    int if_valid = 1;

    // parser
    double expr(bool get);

    double term(bool get);

    double prim(bool get);

    //lexer
    Token_value get_token();

    //error
    double error(const string &e);

};


#endif //OOP_CAL_H
