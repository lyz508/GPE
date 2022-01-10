#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m1, m2;

    while (cin >> n){
        vector<int> input;
        int s = 0;

        for (int i=0, t; i<n; i++){
            cin >> t;
            input.push_back(t);
        }
        sort(input.begin(), input.end());

        m1 = input[(n-1)/2];
        m2 = input[n/2];

        for (int i=0; i<input.size(); i++){
            if (input[i] == m1 || input[i] == m2)
                s ++;
        }

        printf("%d %d %d\n", m1, s, (m2-m1)+1);
    }


    return 0;
}