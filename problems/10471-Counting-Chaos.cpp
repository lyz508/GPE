#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

vector< int > table;

void build(){
    // build table
    for (int i=0, a, b, c, d; i<3000; i++){
        
        a = i % 10;
        b = (i % 100) / 10;
        c = (i % 1000) / 100;
        d = (i % 10000) / 1000;
        
        if (i / 10 == 0){ // 1 digit
            table.push_back(i);
        }
        else if (i / 100 == 0){
            if (i <= 60){
                if (a == b)
                    table.push_back(i);
            }
        }
        else if (i / 1000 == 0){
            if ( b*10+a < 60 ){
                if (a == c)
                    table.push_back(i);
            }
        }
        else if (i / 10000 == 0){
            if (c+10*d <= 23 && b*10+a < 60){
                if (a == d && b == c)
                    table.push_back(i);
            }
        }
    }
}

int main(){
    build();

    int t, num;
    cin >> t;
    for (int i=0; i<t; i++){
        string tmp;
        char output[20];
        cin >> tmp;

        num=0;
        for (int s=0; s<tmp.length(); s++){
            if ( isdigit(tmp[s]) ){
                num = 10*num + (tmp[s] - '0');
            }
        }
        vector<int>::iterator itr = upper_bound(table.begin(), table.end(), num);
        
        // output
        sprintf(output, "%04d", *itr);
        for (int i=0; i<5; i++){
            if (i < 2)
                printf("%c", output[i]);
            else if (i > 2)
                printf("%c", output[i-1]);
            else
                printf(":");
        }
        printf("\n");
    }

    return 0;
}