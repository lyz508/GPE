#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int table[100] = {};

int fp_mod(int n, int p){
    if (p == 1)
        return n;

    int rtn, tmp;
    if (p % 2 != 0){ // odd
        tmp = fp_mod(n, (p-1)/2);
        rtn = n * tmp * tmp;
    }
    else{
        tmp = fp_mod(n, p/2);
        rtn = tmp * tmp;
    }

    return rtn % 10;
}

int main(){
    // build table
    table[0] = 0;
    for (int i=1; i<100; i++){
        table[i] = fp_mod(i, i);
    }

    // in
    string input;
    int num, output = 0;
    while (cin >> input){
        if (input == "0")
            break;
        output = 0;
        if (input.size() > 2)
            num = (input[input.size()-2] - '0') * 10 + (input[input.size()-1] - '0');
        else{
            stringstream ss;
            ss << input;
            ss >> num;
        }
        
        for (int i=0; i<=num; i++)
            output += table[i];
        
        printf("%d\n", output%10);
    }


    return 0;
}