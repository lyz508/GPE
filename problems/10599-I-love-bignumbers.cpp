#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
using namespace std;

vector< string > multi_res;
vector< int > ans;

string Int2Str(int i){
    stringstream ss;
    string rtn;
    ss << i;
    ss >> rtn;
    return rtn;
}

string BigMulti(string a, string b){
    vector< int > n1, n2, res, tmp;
    string rtn = "";

    res.resize(a.length()+b.length()+2);
    for (int i=a.length()-1; i>=0; i--)
        n1.push_back(a[i]-'0');
    for (int i=b.length()-1; i>=0; i--)
        n2.push_back(b[i]-'0');

    //swap 
    if (n1.size() < n2.size()){
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    // multi
    for (int i=0; i<n2.size(); i++){
        for (int j=0; j<n1.size(); j++){
            res[j+i] += n2[i] * n1[j];
        }
    }
    for (int i=0; i<res.size(); i++){
        if (res[i] >= 10){
            res[i+1] += res[i] / 10;
            res[i] %= 10;
        }
    }

    // for (int i=0; i<n1.size(); i++){
    //     printf("%d", n1[i]);
    // }
    // printf("\n");
    // for (int i=0; i<n2.size(); i++){
    //     printf("%d", n2[i]);
    // }
    // printf("\n");
    // for (int i=0; i<res.size(); i++){
    //     printf("%d", res[i]);
    // }


    // output
    for (int i=res.size()-1, f=1; i>=0; i--){
        if (f){
            if (res[i] != 0)
                f = 0;
        }
        if (!f){
            rtn += res[i] + '0';
        }
    }

    return rtn;
}

void build(){
    multi_res.resize(1001);
    ans.resize(1001);
    multi_res[0] = "1";
    for (int i=1; i<1001; i++){
        multi_res[i] = BigMulti(multi_res[i-1], Int2Str(i));
    }

    for (int i=0; i<1001; i++){
        for (int j=0; j<multi_res[i].length(); j++){
            ans[i] += multi_res[i][j]-'0';
        }
    }
}


int main(){
    int n;
    build();
    while (cin >> n){
        cout << ans[n] << "\n";
    }

    return 0;
}