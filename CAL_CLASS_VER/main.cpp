//
// Created by shrik3 on 12/10/16.
//

#include "CAL.h"

using namespace std;

istream *input;

int main(int argc, char* argv[]) {

    CAL A;

    if(1 == argc) A.input = &cin;
    if(2 == argc) A.input = new ifstream(argv[1]);

    A.start();

    return A.no_of_errors;
}
