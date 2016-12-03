//
// Created by emman on 2016/11/25.
//


#include "syms.h"
#include "error.h"
#include "lexer.h"
#include "parser.h"

double expr(bool get) {

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
double prim(bool get) {
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

double term(bool get) {
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






