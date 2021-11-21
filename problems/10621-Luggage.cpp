#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int n, tmp, sum;
    cin >> n;
    cin.ignore();
    while (n--){
        // ini
        sum = 0;

        string str;
        stringstream ss;
        vector<int> v;
        getline(cin, str);  
        ss << str;
        while (ss >> tmp){
            v.push_back(tmp);
            sum += tmp;
        }

        if (sum%2 != 0){
            printf("NO\n");
            continue;
        }

        vector<bool> canHandle = vector<bool>(sum+1, false);
        canHandle[0] = true;
        for (int i=0; i<v.size(); i++){
            for (int j=sum; j>=v[i]; j--){
                if (canHandle[j - v[i]]){
                    canHandle[j] = true;
                }
            }
        }

        if (canHandle[sum/2])
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}