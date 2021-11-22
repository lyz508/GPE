#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int t, tmp;
    cin >> t;
    cin.ignore();

    while (t--){
        vector<int> v;
        string ipt;
        stringstream ss;
        int sum = 0;

        getline(cin, ipt);
        ss << ipt;
        while (ss >> tmp){
            v.push_back(tmp);
            sum += tmp;
        }

        // skip odd
        if (sum % 2 != 0){
            printf("NO\n");
            continue;
        }

        vector<bool> canPut = vector<bool>(sum+1, false);
        canPut[0] = true; // put nothing

        for (int i=0; i<v.size(); i++){
            for (int j=sum; j>=v[i]; j--){
                if (canPut[j - v[i]]) // last weight can be reached by put sth
                    canPut[j] = true;
            }
        }

        printf("%s\n", (canPut[sum/2]) ? "YES":"NO");
    }

    return 0;
}