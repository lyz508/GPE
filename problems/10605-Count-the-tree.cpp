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

string toString(vector<int> v){
    string rtn;
    stringstream ss;
    for (int i=0; i<v.size(); i++)
        ss << v[i];
    ss >> rtn;
    return rtn;
}

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

string BigMulti(string n1, string n2){
    vector<int> sum(n1.size()+n2.size()+3, 0);
    if (n1.size() < n2.size()){
        string tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    for (int i=n2.size()-1; i>=0; i--){
        for (int j=n1.size()-1; j>=0; j--){
            sum[(n2.size()-1-i)+(n1.size()-1-j)] += 
                (n1[j]-'0') * (n2[i]-'0');
        }
    }

    for (int i=0; i<sum.size()-1; i++){
        if (sum[i] > 9){
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
    }

    // erase 0
    reverse(sum.begin(), sum.end());
    while (sum.size() > 0 && sum[0] == 0)
        sum.erase(sum.begin());
    // judge 0
    if (sum.size() == 0)
        sum.push_back(0);

    return toString(sum);
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