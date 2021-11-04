#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int train(vector<int> v){
    int ans=0;
    for (int i=1; i<v.size(); i++){
        for (int j=0; j<v.size()-i; j++){
            if (v[j] > v[j+1]){
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
                ans++;
            }
        }
    }
    return ans;
}


int main(){
    int cases, l, tmp, ans;
    vector<int> v;
    
    cin >> cases;
    while (cases--){
        v.clear();
        cin >> l;
        while (l --){
            cin >> tmp;
            v.push_back(tmp);
        }
        ans = train(v);
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }

    return 0;
}