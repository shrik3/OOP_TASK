

# include "error.h"


double error(const string& e) {
    no_of_errors ++;
    cerr << "error:" << e << " @ line " << curr_line << endl;
    return 1;
}

