#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s1, s2;

    while (cin >> s1 >> s2){
        vector< char > v;
        // compare s1, s2
        for (int i=0; i<s1.size(); i++){
            for (int j=0; j<s2.size(); j++){
                if (s1[i] == s2[j]){ // common -> erase in s2
                    v.push_back(s1[i]);
                    s2.erase(s2.begin() + j);
                    break;
                }
            }
        }
        sort(v.begin(), v.end());
        for (int i=0; i<v.size(); i++){
            printf("%c", v[i]);
        }
        printf("\n");
    }


    return 0;
}