#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int t, t1;
    cin >> t;
    cin.ignore();

    while (t--){
        int sum;
        vector<int> v;
        string tmp;
        stringstream ss;

        getline(cin, tmp);
        ss << tmp;
        while (ss >> t1){
            v.push_back(t1);
            sum += t1;
        }

        if (sum % 2 != 0){
            printf("NO\n");
            continue;
        }

        vector<bool> canPut = vector<bool>(sum+1, false);
        canPut[0] = true;

        for (int i=0; i<v.size(); i++){
            for (int j=sum; j>=v[i]; j--){
                if (canPut[j - v[i]])
                    canPut[j] = true;
            }
        }

        printf("%s\n", (canPut[sum/2])?"YES", "NO");
    }


    return 0;
}