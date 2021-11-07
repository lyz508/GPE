#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

vector< string > dp;
vector< string > fac;

string BigMulti(string s1, string s2){
    string res = "";
    vector< int > n1, n2, sum, tmp;

    for (int i=0; i<s1.length(); i++)
        n1.push_back(s1[i] - '0');
    for (int i=0; i<s2.length(); i++)
        n2.push_back(s2[i] - '0');
    sum.resize(n1.size() + n2.size() + 1);

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    // switch
    if (n1.size() < n2.size()){
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    // multi
    for (int i=0; i<n2.size(); i++){
        for (int j=0; j<n1.size(); j++){
            sum[i+j] += n2[i]*n1[j];
        }
    }

    // carry
    for (int i=0; i<sum.size(); i++){
        if (sum[i] >= 10){
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
    }

    // output
    bool f = false;
    for (int i=sum.size()-1; i>=0; i--){
        if (!f){
            if (sum[i] != 0)
                f = true;
        }
        if (f){
            res += '0' + sum[i];
        }
    }

    return res;
}

string BigAdd(string s1, string s2){
    vector< int > n1, n2, sum, tmp;
    string res = "";
    bool f = false;

    for (int i=0; i<s1.length(); i++)
        n1.push_back(s1[i] - '0');
    for (int i=0; i<s2.length(); i++)
        n2.push_back(s2[i] - '0');

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());


    // switch
    if (n1.size() < n2.size()){
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    sum.resize(n1.size() + 10);


    // add
    for (int i=0, t; i<sum.size()-1; i++){
        // for (int i=0; i<n1.size(); i++){
        //     printf("%d", n1[i]);
        // }
        // printf("\n");
        // for (int i=0; i<n2.size(); i++){
        //     printf("%d", n2[i]);
        // }
        // printf("\n");
        // for (int i=0; i<sum.size(); i++){
        //     printf("%d", sum[i]);
        // }
        // printf("\n");


        if (i < n2.size()){
            t = n1[i] + n2[i] + sum[i];
            sum[i] = t % 10;
            sum[i+1] += t / 10;
        }
        else if (i < n1.size()){
            sum[i+1] += n1[i] / 10;
            sum[i] += n1[i] % 10;
        }
        else{
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
    }

    for (int i=sum.size()-1; i>=0; i--){
        if (!f){
            if (sum[i] != 0)
                f = true;
        }
        if (f)
            res += '0' + sum[i];
    }


    return res;
}

string toStr(int n){
    stringstream ss;
    ss << n;
    string rtn;
    ss >> rtn;
    return rtn;
}

void Catalan(){
    dp.resize(301);
    dp[0] = "1";
    dp[1] = "1";
    for (int n=2; n<301; n++){
        string sum = "0";
        for (int i=0; i<n; i++){
            sum = BigAdd(sum, BigMulti(dp[i], dp[n-1-i]));
        }
        dp[n] = sum;
    }

    // factorail
    fac.resize(301);
    fac[0] = "1";
    fac[1] = "1";
    for (int n=2; n<301; n++){
        string sum = "1";
        for (int i=2; i<=n; i++)
            sum = BigMulti(sum, toStr(i));
        fac[n] = sum;
    }

    for (int i=0; i<301; i++){
        dp[i] = BigMulti(dp[i], fac[i]);
    }
}

int main(){
    Catalan();

    int tmp;
    while (cin >> tmp && tmp != 0){
        printf("%s\n", dp[tmp].c_str());
    }

    return 0;
}