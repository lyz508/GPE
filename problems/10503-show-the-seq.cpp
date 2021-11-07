#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <sstream>
using namespace std;

bool have_path(string str){
    for (int i=0; i<str.length(); i++){
        if (str[i] == '[')
            return true;
    }
    return false;
}

int toInt(string str){
    stringstream ss;
    int rtn;
    ss << str;
    ss >> rtn;
    return rtn;
}

int sequence(string str, int t, bool f){
    if (! have_path(str) ) // end condition
        return toInt(str);
    
    vector< int > v;
    string num = "";
    int type = 0, n;

    for (int i=0; i<str.length(); i++){
        if ( str[i] != '+' && str[i] != '*'){
            num += str[i];
        }
        else{
            if (str[i] == '+')
                type = -1;
            else if (str[i] == '*')
                type = 1;
            str = str.substr(i+2, (int)(str.length()-2)-(i+3) );
            break;
        }
    }
    n = toInt(num);

    for (int i=0; i<t; i++){
        if (type == -1){
            if (i == 0)
                v.push_back(n);
            else
                v.push_back(v[i-1] + sequence(str, i, false));
        }
        if (type == 1){
            if (i == 0)
                v.push_back( n * sequence(str, 1, false) );
            else
                v.push_back( v[i-1] * sequence(str, i+1, false));
        }
    }

    if (f){
        for (int i=0; i<t; i++){
            printf("%d", v[i]);
            if ( i!=t-1 )
                printf(" ");
        }
        printf("\n");
    }
    return v[t-1];
}


int main(){
    string tmp;
    int n;

    while (cin >> tmp >> n){
        int ans;
        tmp = tmp.substr(1, tmp.length()-2);
        sequence(tmp, n, true);
    }

    return 0;
}