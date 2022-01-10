#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s1, s2;
    while (cin >> s1 >> s2){
        vector<char> v;

        if (s1.size() < s2.size()){
            string tmp = s1;
            s1 = s2;
            s2 = tmp;
        }

        for (int i=0; i<s2.size(); i++){
            for (int j=0; j<s1.size(); j++){
                if (s1[j] == s2[i]){
                    v.push_back(s2[i]);
                    s1.erase(s1.begin() + j);
                    break;
                }
            }
        }
        sort(v.begin(), v.end());
        for (int i=0; i<v.size(); i++)
            printf("%c", v[i]);
        printf("\n");
    }

    return 0;
}