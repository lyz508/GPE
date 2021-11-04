#include <iostream>
#include <vector>
using namespace std;

int main(){
    int total, time, t1, t2, c;
    vector<int> num1, num2, sum1;
    vector< vector<int> > res;

    cin >> total;

    while (total--){
        // ini
        num1.clear(); 
        num2.clear();
        sum1.clear();
        c = 0;

        cin >> time;
        for (int i=0; i<time; i++){
            cin >> t1 >> t2;
            num1.push_back(t1);
            num2.push_back(t2);
        }

        for (int i=time-1; i>=0; i--){
            c = num1[i] + num2[i];
            if (c / 10 != 0){
                if (i == 0){
                    sum1.push_back(c % 10);
                    sum1.push_back(1);
                }
                else{
                    sum1.push_back(c % 10);
                    num1[i-1] ++;
                }
            }
            else{
                sum1.push_back(c);
            }
        }

        res.push_back(sum1);
    }

    // output
    for (int t=0; t<res.size(); t++){
        for (int i=res[t].size()-1; i>=0; i--){
            cout << res[t][i];
        }
        if (t != res.size()-1)
            cout << "\n\n";
        else
            cout << "\n";
    }
        

    return 0;
}