//
// Created by shrik3 on 12/11/2016.
//

#include <string>
#include <iostream>

using namespace std;

char* itoa(int i,char b[]){
    int j = 0;
    char c[255];
    int absi = i>=0?i:-i;
    while(absi>0){
        c[j++]=absi%10+48;
        absi/=10;
    }
    if(i<0){
        c[j++]='-';
    }
    for(int i =0;i<j;i++){
        b[i] = c[j-i-1];
    } 
    return b;
}

int main(){
    char b[255];
    cout << itoa(-123,b) <<endl;

    return 0;
}
