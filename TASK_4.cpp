
/*
 * by shrik3 @ 2016.11
 * Write a program like ‘‘Hello, world!’’ that takes a name
 * as a command-line argument and writes ‘‘Hello, name!’’.
 * Modify this program to take any number of names as arguments
 * and to say hello to each.
 */


#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc;i++){
        printf("Hello , %s !\n",argv[i]);
    }

        return 0;
}