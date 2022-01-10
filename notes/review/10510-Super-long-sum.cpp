#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

string BigAdd(string num1, string num2){
    if (num1.size() < num2.size()){
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    for (int i=num1.size()-1, j=num2.size()-1; i>=0; i--, j--){
        num1[i] = num1[i] + (num2[j] - '0');
    }

    for (int i=num1.size()-1; i>0; i--){
        if (num1[i] > '9'){
            num1[i-1] += (num1[i] - '0')/10;
            num1[i] = '0' + (num1[i] - '0') % 10;
        }
    }

    if (num1[0] > '9'){
        num1[0] = '0' + (num1[0] - '0')%10;
        num1 = '1' + num1;
    }

    return num1;
}

int main(){
    int t, w;
    vector<string> v;

    cin >> t;

    while (t--){
        string n1="", n2="", t1, t2;

        cin >> w;
        while (w--){
            cin >> t1 >> t2;
            n1 += t1;
            n2 += t2;
        }

        v.push_back(BigAdd(n1, n2));
    }

    for (int i=0; i<v.size(); i++){
        if (i != v.size()-1){
            printf("%s\n\n", v[i].c_str());
        }
        else
            printf("%s\n", v[i].c_str());
    }

    return 0;
}