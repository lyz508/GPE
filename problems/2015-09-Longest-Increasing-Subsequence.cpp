#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

void LIS(vector<int> v){
    vector<int> len = vector<int>(v.size(), 1),
                prev = vector<int>(v.size(), -1);
    int m = 1;
    for (int i=0; i<v.size(); i++){
        for (int j=i+1; j<v.size(); j++){
            if (len[i] + 1 > len[j] && v[j] > v[i]){
                len[j] = len[i] + 1;
                prev[j] = i;
            }
        }
    }

    for (int i=0; i<v.size(); i++)
        m = max(m, len[i]);
    printf("%d\n", m);
}

int main(){
    int n;
    vector<int> v;
    cin >> n;
    for (int i=0, tmp; i<n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
        
    LIS(v);

    return 0;
}