

# include "error.h"


double error(string e) {
    no_of_errors ++;
    cerr << "error:" << e << endl;
    return 1;
}

