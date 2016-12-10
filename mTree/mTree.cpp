#include "mTree.h"
#include <iostream>

using namespace std;

int mTree::insert() {
    cout << "INSERT YOUR WORDS, END WITH '$'" << endl;
    for (;;) {
        string e;
        cin >> e;
        if (e == "$")break;
        // CODE FOR NODE INSERTION
        BiTreeInsert(this->root,e);

    } // for
}

void mTree::print() {
    dictOrderPrint(root);
}

int mTree::dictOrderPrint(Tnode *T) {
    if (T) {
        dictOrderPrint(T->left);
        if(T->count!=0) {
            cout << T->word << " ";
            cout << T->count << endl;
        }
        dictOrderPrint(T->right);

    }
}

int mTree::BiTreeInsert(Tnode* T, string e) {
    if (e == T->word) {
        T->count++;
        return 1;
    } else if (e < T->word) {
        if (!T->left) {
            T->left = new Tnode;
            T->left->word = e;
            T->left->count++;
        } else return (BiTreeInsert(T->left, e));

    } else {
        if (!T->right) {
            T->right = new Tnode;
            T->right->word = e;
            T->right->count++;
        } else return (BiTreeInsert(T->right, e));

    }
    return 1;

}


