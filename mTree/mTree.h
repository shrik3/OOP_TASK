//
// Created by shrik3 on 12/10/16.
//

#ifndef OOP_MTREE_H
#define OOP_MTREE_H

#include <iostream>
#include <string>
using namespace std;

class Tnode {
public:
    string word = "";
    int count = 0;
    Tnode *left = NULL;
    Tnode *right = NULL;
};


class mTree {
public:
    Tnode * root = new Tnode;
    int insert();
    void print();
private:
    int BiTreeInsert(Tnode * T, string e);
    int dictOrderPrint(Tnode *T);
};


#endif //OOP_MTREE_H
