//
// Created by shrik3 on 11/11/2016.
//


#include <string>
#include <iostream>


using namespace std;

double atoi(char *num) {
    int flag = 1;
    if (num[0] == '+') {
        for (int t = 0; num[t] != '\0'; t++) {
            num[t] = num[t + 1];
        }
    }
    if (num[0] == '-') {
        flag = -1;
        for (int t = 0; num[t] != '\0'; t++) {
            num[t] = num[t + 1];
        }
    }

    for(int t =0;num[t]!='\0';t++){
        if(num[t]=='\\'){
            char c;
            if(num[t+1]=='x'||num[t+1]=='X'){
                char subString[5];
                subString[0] = '0';
                subString[1] = 'x';
                subString[2] = num[t+2];
                subString[3] = num[t+3];
                c = char(atoi(subString));
            }else{
                char subString[4];
                subString[0] = '0';
                subString[1] = num[t+2];
                subString[2] = num[t+3];
                c = char(atoi(subString));
            }
            num[t]=c;
            for(int i=t+1;num[i+1]!='\0';i++){
                num[t] = num[t+2];
            }
        }

    }

    double result = 0;
    int i = 0;
    int base = 0;
    if (num[0] == 48 && (num[1] == 88 || num[1] == 120)) {
        i = 0;
        while (num[i] != '\0') {
            if (num[i] >= 65 && num[i] <= 71)
                num[i] -= 7;
            if (num[i] >= 97 && num[i] <= 103)
                num[i] -= 39;
            i++;
        }
        base = 16;
        i = 2;
    } else if (num[0] == 48 && (num[1] >= 48 && num[1] <= 56)) {
        base = 8;
        i = 1;
    } else if (num[0] >= 48 && num[1] <= 58)
        base = 10;
    else return 0;
    for (; num[i] != '\0'; i++)
        result = result * base + num[i] - 48;
    return result * flag;
}

int main() {
    char str[255];
    cout << "INPUT STRING,END WITH '.':\n";
    for (;;) {
        cin >> str;
        if (str[0] == '.')break;
        double istr = atoi(str);
        cout << istr << endl;
    }
    return 0;
}




