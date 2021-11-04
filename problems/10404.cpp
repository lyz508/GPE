#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void initv(vector<int> &v){
    v.clear();
    v.resize(20);
}

int main(){
    long int n1, n2;
    int c, count;
    while (cin >> n1 >> n2){
        if (n1 == 0 && n2 == 0) break;
        c = 0;
        count = 0;
        while (n1 != 0 || n2 != 0){
            if (n1%10 + n2%10 + c >= 10){
                c = 1;
                count ++;
            }
            else{
                c = 0;
            }
            n1 /= 10;
            n2 /= 10;
        }
        if (count == 0)
            printf("No carry operation.\n");
        else if (count == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", count);
    }


    return 0;
}