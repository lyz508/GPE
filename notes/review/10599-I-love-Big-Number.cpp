#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string toString(vector<int> v){
    string rtn;
    stringstream ss;
    for (int i=0; i<v.size(); i++)
        ss << v[i];
    ss >> rtn;
    return rtn;
}

string int2Str(int n){
    stringstream ss;
    string rtn;
    ss << n;
    ss >> rtn;
    return rtn;
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
                (n1[j] - '0') * (n2[i] - '0');
        }
    }

    for (int i=0; i<sum.size()-1; i++){
        if (sum[i] > 9){
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
    }

    reverse(sum.begin(), sum.end());
    while (sum.size() > 0 && sum[0] == 0)
        sum.erase(sum.begin());
    if (sum.size() == 0)
        sum.push_back(0);

    return toString(sum);
}

vector<string> fac(1001, "0");
vector<int> table(1001, 0);
void build(){
    fac[0] = "1";
    table[0] = 1;

    for (int i=1; i<1001; i++){
        int tmp = 0;
        fac[i] = BigMulti(fac[i-1], int2Str(i));

        for (int c=0; c<fac[i].size(); c++)
            tmp += fac[i][c]-'0';
        table[i] = tmp;
    }
}

int main(){
    build();
    int n;
    while(cin >> n)
        printf("%d\n", table[n]);
    return 0;
}