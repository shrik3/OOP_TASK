/*
 * Write an error function that takes a printf-style format string containing %s, %c, and %d
 * directives and an arbitrary number of arguments. Don’t use printf(). Look at §21.8 if you
 * don’t know the meaning of %s, %c, and %d. Use <cstdarg>.
 */

#include <stdarg.h>
#include <string>
#include <iostream>


using namespace std;

int error(const char *format, ...) {
    string f = format;
    va_list argp;
    va_start(argp, format);

    for (int i = 0; i < f.length(); i++) {
        if (f[i] != '%') cout << f[i];
        else {
            switch (f[++i]) {
                default:
                    break;
                case 'd': {
                    int temp = va_arg(argp, int);
                    cout << temp;
                    break;
                }
                case 's': {
                    string temp = va_arg(argp, string);
                    cout << temp;
                    break;
                }
                case 'c': {
                    char temp = char(va_arg(argp, int));
                    cout << temp;
                    break;
                }
            }
        }
    }

}


int main() {
    string a = "STRING";
    error("fuck%d%s%c", 123,a,'c');
    return 0;

}