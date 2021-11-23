#include <iostream>lovve 
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int return_num(string name){
    int res = 0;
    for (int i=0; i<name.length(); i++){
        if (name[i] >= 'A' && name[i] <= 'Z'){
            res += name[i] - 'A' + 1;
        }
        else if (name[i] >= 'a' && name[i] <= 'z'){
            res += name[i] - 'a' + 1;
        }
    }

    while (res / 10 != 0){
        int a = 0, tmp = res;
        while (tmp / 10 != 0){
            a += tmp % 10;
            tmp /= 10;
        }
        a += tmp;
        res = a;
    }

    return res;
}

int main(){
    string s1, s2;
    int a, b;
    double per;
    while (getline(cin, s1)){
        getline(cin, s2);
        // printf("%s, %s", s1.c_str(), s2.c_str());
        a = return_num(s1);
        b = return_num(s2);
        printf("%.2lf %\n", (double)min(a, b)/(double)max(a, b) * 100);
    }


    return 0;
}