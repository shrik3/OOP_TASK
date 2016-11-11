// P140 3.

#include <iostream>
#include <string>
#include <map>

using namespace std;

class info {
public:
    //string name;      #not used ..
    double sum;
    int count;

    info() {
        //  name = '';
        sum = 0;
        count = 0;
    }
};

typedef map<string, info> dict;
dict data;

int main() {
    string name = "";
    double value = 0;
    cout << "INPUT YOUR INFO SEQUENCE, AND END WITH 'ENDSEQ'" << endl;
    for (;;) {
        cin >> name;
        if (name == "ENDSEQ") break;
        cin >> value;
        info &curinfo = data[name];
        curinfo.count++;
        curinfo.sum += value;
    }


    dict::iterator it = data.begin();
    for(;it!=data.end();++it){
        string curname = it->first;
        double cursum = it->second.sum;
        int curcount = it->second.count;
        double average = cursum/curcount;
        cout << "name: "<<curname<<" sum: "<<cursum<<" average: "<<average<<endl;
    }


    return 0;
}
