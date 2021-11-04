#include <iostream>
#include <sstream>
#include <ctype.h>
using namespace std;
int main() {
  string s;
  char ch[26]={'1','V','X','S','W','D','F','G','U','H',
               'J','K','N','B','I','O','1','E','A','R',
               'Y','C','Q','Z','T','1'};
  char input[20]={'-','=','[',']','\\',';','\'',',','.','/',
                  '0','1','2','3','4','5','6','7','8','9'};
  char output[20]={'0','-','P','[',']','L',';','M',',','.',
                  '9','`','1','2','3','4','5','6','7','8'};
  while (getline(cin,s)){
    for(int i=0;i<s.length();i++){
      if (s[i]==' ') cout << ' ';
      else if (isalpha(s[i])) cout << ch[s[i]-'A'];        
      else {
        for(int j=0;j<20;j++){
          if (s[i]==input[j]) {
            cout << output[j];
            break;                    
          }        
        }     
      }      
    }
    cout << endl;             
  }
}