//
// Created by shrik3 on 12/10/16.
//
#include "CAL.h"

void CAL::start() {
    curr_tok = PRINT;
    mtable["pi"] = 3.14;
    mtable["e"] = 2.71;
    while((*input)){
        get_token();
        if(curr_tok == END) break;
        if(curr_tok == PRINT) {
            continue;
        }
        double result;
        result = expr(false);
        if(if_valid==1){
            cout<<result<<endl;
        }
        curr_line +=1;
    }
}

double CAL::expr(bool get) {

    double left = term(get);
    for (;;) {
        switch (curr_tok) {
            case PLUS:
                left += term(true);
                break;
            case MINUS:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}

double CAL::prim(bool get) {
    if (get) get_token();

    switch (curr_tok) {
        case NUMBER: {
            double v = number_value;
            get_token();
            return v;
        }
        case NAME: {
            double &v = mtable[string_value];
            if (get_token() == ASSIGN) v = expr(true);
            return v;
        }
        case MINUS:
            return -prim(true);
        case LP: {
            double e = expr(true);
            if (curr_tok != RP) {
                if_valid = 0;
                return error(") expected");
            }

            get_token();
            return e;
        }
        default:
            if_valid = 0;
            return error("primary expected");
    }
}

double CAL::term(bool get) {
    double left = prim(get);
    for (;;) {
        switch (curr_tok) {
            case MUL:
                left *= prim(true);
                break;
            case DIV:
                if (double d = prim(true)) {
                    left /= d;
                    break;
                }
                if_valid = 0;
                return error("DIVIDED BY 0");
            default:
                return left;
        }
    }

}


Token_value CAL::get_token() {
    using namespace std;
    char ch = 0;
    (*input) >> ch;
    switch (ch) {
        case 0:
            return curr_tok = END;
        case ';':
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return curr_tok = Token_value(ch);
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
        case '.':
            (*input).putback(ch);
            (*input) >> number_value;
            return curr_tok = NUMBER;
        default:
            if (isalpha(ch)) {
                (*input).putback(ch);
                (*input) >> string_value;
                return curr_tok = NAME;
            }
            error("bad token");
            if_valid = 0;
            return curr_tok = PRINT;
    }
}

double CAL::error(const string &e) {
    no_of_errors ++;
    cerr << "error:" << e << " @ line " << curr_line << endl;
    return 1;
}
