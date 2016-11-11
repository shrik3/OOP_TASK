//
// Created by shrik3 on 11/11/2016.
//


#include <string>
#include <iostream>


using namespace std;

double atoi(char* num)
{
    int flag = 1;
    if(num[0]=='+'){
        for(int t=0;num[t]!='\0';t++){
            num[t]=num[t+1];
        }
    }
    if(num[0]=='-'){
        flag = -1;
        for(int t=0;num[t]!='\0';t++){
            num[t]=num[t+1];
        }
    }

    double inum=0;
    int i=0;
    int base=0;
// 十六进制时,0X 或 0x 开头,如: 0xff
    if ( num[0]==48 && ( num[1]==88 || num[1]==120) )
    {
        i=0;
        while (num[i]!='\0')
        {
            if (num[i] >= 65 && num[i] <= 71) //abcdef小写时
                num[i]-=7 ;
            if (num[i] >= 97 && num[i] <= 103) //ABCDEF大写时
                num[i]-=39 ;
            i++;
        }
        base = 16;
        i=2;
    }
// 八进制时,0 开头,如: 022
    else if ( num[0]==48 && ( num[1]>=48 && num[1]<=56) )
    {
        base = 8;
        i=1;
    }
// 十进制时,以数字开头,如:90
    else if ( num[0]>=48 && num[1]<=56)
        base = 10;
    else return 0; //异常情况
    for( ; num[i]!='\0'; i++)
        inum = inum*base + num[i] - 48 ;
    return inum*flag;
}

int main()
{
    char str[255];
    cout<<"INPUT STRING,END WITH '.':\n";
    for(;;) {
        cin >> str;
        if(str[0]=='.')break;
        double istr = atoi(str);
        cout << istr << endl;
    }
    return 0;
}




