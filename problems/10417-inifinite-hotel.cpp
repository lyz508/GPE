#include <iostream>
using namespace std;

int main(){
    long long l, s;
    while ( cin >> s >> l ){
        while ( 1 ){
            l -= s;
            if ( l <= 0 ) break;
            s++;
        }
        cout << s << "\n";
    }

    return 0;
}