//
// Created by emman on 2016/11/25.
//

#include<iostream>
#include "syms.h"
#include "lexer.h"
#include "parser.h"

using namespace std;

int main() {

    curr_tok = PRINT;
    table["pi"] = 3.14;
    table["e"] = 2.71;
    while(cin){
        get_token();
        if(curr_tok == END) break;
        if(curr_tok == PRINT) continue;
        cout << expr(false) << endl;


    }


    return no_of_errors;
}