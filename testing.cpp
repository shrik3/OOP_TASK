//
// Created by emman on 2016/11/18.
//

// this is a test

#include <iostream>
#include <string>

using namespace std;

int main (){
    char * a = NULL;
    a = new char[100];
    string e = "this is a test";

    for (int i = 0; i < e.size(); i++) a[i] = e[i];
    string d = a ;
    cout << a << endl;
    cout << d;
    return 0;

}

