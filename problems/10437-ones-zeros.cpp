#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string str;
    int t = 1;

    while (getline(cin, str) && str.length() != 0){
        vector< double > r;
        vector< int >::iterator itr;
        char last;
        int c;
        double a, b;

        // record diff pts
        for (int i=0; i<str.length(); i++){
            if (i!=0){
                if (last != str[i])
                    r.push_back(i-0.5);
            }
            last = str[i];
        }

        // cases
        cin >> c;
        printf("Case %d:\n", t++);

        for (int i=0, t1, t2; i<c; i++){
            cin >> t1 >> t2;
            a = max(t1, t2);
            b = min(t1, t2);

            int is = -1;
            for (int j=0; j<r.size(); j++){
                if (r[j] >= b && r[j] <= a){
                    is = j;
                    break;
                }
            }
            if (is == -1)
                printf("Yes\n");
            else
                printf("No\n");
        }

        cin.ignore();
    }


    return 0;
}