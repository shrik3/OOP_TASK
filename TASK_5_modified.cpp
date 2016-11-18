/*
 * by shrik3 @ 2016.11
 *
 * consider : struct Tnode{string word; int count ; Tnode * left; Tnode * right};
 * Write a function for entering new words into a tree of Tnodes.
 * Write a function to write out a tree of Tnodes.
 * Write a function to write out a tree of Tnodes with the words in alphabetical order.
 * Modify Tnode so that it stores (only) a pointer to an arbitrarily long word stored
 * as an array of characters on free store using new. Modify the functions to use the new definition of Tnode.
 */


#include <iostream>
#include <string>

using namespace std;

struct Tnode {
    char *word;
    int count = 0;
    Tnode *left = NULL;
    Tnode *right = NULL;
};

typedef Tnode *BTree;


int BiTreeInsert(BTree T, string e) {
    string temp = T->word;


    if (e == temp) {
        T->count++;
        return 1;
    } else if (e < temp) {
        if (!T->left) {
            T->left = new Tnode;
            T->left->word = new char[100];
            int len = e.size();
            e.copy(T->left->word,len,0);
            T->left->word[len]='\0';
            T->left->count++;
        } else return (BiTreeInsert(T->left, e));

    } else {
        if (!T->right) {
            T->right = new Tnode;
            T->right->word = new char[100];
            int len = e.size();
            e.copy(T->right->word,len,0);
            T->right->word[len]='\0';
            T->right->count++;
        } else return (BiTreeInsert(T->right, e));

    }
    return 1;

}


int normalPrint(Tnode *T){
    if(T){
        normalPrint(T->left);
        normalPrint(T->right);
        cout << T->word<<" ";
    }

}

int dictOrderPrint(Tnode *T){
    if(T){
        dictOrderPrint(T->left);
        cout << T->word<<" ";
        dictOrderPrint(T->right);
    }

}


int main() {
    cout << "INPUT WORDS, DIVIDE WITH SPACE , END THREAD WITH '$'\n";
    Tnode T;
    T.word = new char[100];
    string e ;
    cin >> e ;
    if (e=="$") return 0;
    for (int i = 0; i < e.size(); i++) T.word[i] = e[i];
    T.word[e.size()]='\0';
    for(;;){
        string e;
        cin>> e;
        if(e=="$")break;
        BiTreeInsert(&T,e);
    }
    cout << "THIS IS THE NORMAL OUTPUT:\n";
    normalPrint(&T);
    cout << "\n\n THIS IS THE ORDER OUTPUT:\n";
    dictOrderPrint(&T);
    return 0;
}


