#include <iostream>
using namespace std;

int table[13] = {-1, 10, 21, -1, 4, 9, 6, 11, 8, 5, 10, 7, 12},
    day[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"},
    rdays[7] = {"Monday", "Sunday", "Saturday", "Friday", "Thursday", "Wednesday", "Tuesday"};

int main(){
    int c, m, d, diff;
    cin >> c;
    while (c--){
        cin >> m >> d;
        if (table[m] != -1){
            diff = d - table[m];
            if (diff > 0)
                cout << days[diff % 7] << "\n";
            else if (diff < 0){
                diff = -diff;
                cout << rdays[diff % 7] << "\n";
            }
            else
                cout << days[0] << "\n";
        }
        else{
            diff = 7 + d;
            cout << days[diff % 7] << "\n";
        }
    }


    return 0;
}