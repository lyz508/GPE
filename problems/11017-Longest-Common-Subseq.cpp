#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

string s1, s2;

void LCS(){
    vector< vector<int> > len(s1.size(), vector<int>(s2.size(), 0));

    for (int i=1; i<s1.size(); i++){
        for (int j=1; j<s2.size(); j++){
            if (s1[i] == s2[j])
                len[i][j] = len[i-1][j-1] + 1;
            else
                len[i][j] = max(len[i-1][j], len[i][j-1]);
        }
    }

    // longest length
    printf("%d\n", len[s1.size()-1][s2.size()-1]);
}

int main(){
    while (cin >> s1 >> s2){
        s1 = '0'+s1;
        s2 = '2'+s2;
        LCS();
    }
    return 0;
}