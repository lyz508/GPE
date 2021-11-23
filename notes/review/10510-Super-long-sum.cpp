#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

string BigAdd(string n1, string n2){
    if (n1.size() < n2.size()){
        string tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    for (int i=n2.size()-1, j=n1.size()-1; i>=0; i--, j--){
        n1[j] = n1[j] + (n2[i]-'0');
    }

    for (int i=n1.size()-1; i>0; i--){
        if (n1[i] > '9'){
            n1[i-1] += (n1[i]-'0')/10;
            n1[i] = '0'+(n1[i]-'0')%10;
        }
    }

    if (n1[0] > '9'){
        n1[0] = '0'+(n1[0]-'0')%10;
        n1 = '1'+n1;
    }
    
    return n1;
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