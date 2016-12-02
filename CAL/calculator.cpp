//
// Created by emman on 2016/11/25.
//

#include<iostream>
#include <cstdlib>
#include "syms.h"
#include "lexer.h"
#include "parser.h"
#include <fstream>

using namespace std;
extern map<string,double> mtable;

istream *input;

int main(int argc, char* argv[]) {
    if(1 == argc) input = &cin;
    if(2 == argc) input = new ifstream(argv[1]);
    if(2 < argc)exit(1);

    curr_tok = PRINT;
    mtable["pi"] = 3.14;
    mtable["e"] = 2.71;
    while((*input)){
        get_token();
        if(curr_tok == END) break;
        if(curr_tok == PRINT) {
            continue;
        }
        cout << expr(false) << endl;
        curr_line +=1;

    }


    return no_of_errors;
}