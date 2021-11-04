#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

struct Ch{
    string ch;
    int n;
};

bool cmp(Ch a, Ch b){
    if (a.n < b.n)
        return false;
    if (a.n == b.n && (int)a.ch[0] > (int)b.ch[0])
        return false;
    return true;
}

int isAlpha(char c){
    if (c-'A' >= 0 && c-'A' < 26)
        return c-'A';
    else if (c-'a' >= 0 && c-'a' < 26)
        return c-'a';
    return -1;
}

void renew(vector<Ch> &v){
    v.clear();
    v.resize(26);
    for (int i=0; i<26; i++){
        v[i].ch = (int)'A' + i;
        v[i].n = 0;
    }
}

int main(){
    vector<Ch> v;
    int cases;
    string tmp;
    
    cin >> cases;
    getchar();
    renew(v);
    while (cases --){
        getline(cin, tmp);
        for (int i=0; i<tmp.length(); i++){
            if (isAlpha(tmp[i]) != -1){
                v[isAlpha(tmp[i])].n ++;
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i=0; i<26; i++){
        if (v[i].n == 0) break;
        printf("%c %d\n", v[i].ch[0], v[i].n);
    }
    

    return 0;
}