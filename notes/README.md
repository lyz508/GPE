---
title: C++ Lib
tags: Cpp
description: cpp libs, including techinique and use
---

# GPE - Notice
- range of data struct
    - `int`: -2147483648 ~ 2147483647
    - `unsigned int`: 0 ~ 4,294,967,295 (2 ^ 32 -1)
    - `long long int`: -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 (2 ^ 64) (1.XXXX * 10^19)
## Notice
- Presentation error
    - 注意換行，可能情況:
        1. 換行問題。
        2. 隔空行，注意最後面的換行。
- struct
    - dont use inside initialization
- memset
    - include in \<cstring>
- for input
    - `cin` and `getline` should notice
    - use `cin.ignore()` to avoid them (clear `endl` in buffer)
- pointer
    - 沒有`nullptr`!!
## Input
- or input
    - `cin` and `getline` should notice
    - use `cin.ignore()` to avoid them (clear `endl` in buffer)
- split with word
    - use `string::find` and `string::substr`
        - if cant find, it will return `string::npos`
    ```cpp=
    string str = "Hello/People",
           parse = '/';
    
    cout << str.substr(0, str.find('/')) << endl;
    
    // with multiple parser
    while (str.find('/') != string::npos){
        cout << str.substr(0, str.find('/')) << endl;
        str.erase(0, str.find('/')+parse.length());
    }
    ```
- lexicographical_compare
    - use `algorithm::sort` on string to get it

### Gain Input
- iostream
- cstdio
    - sscanf, sprintf
- getchar
    - `char c = (char)getchar();`

## Treat Number
### cmath
- `cmath.round`
    - deal with number
    - round to integer

### Convert to integer
- `atoi`, `stoi`
    - stoi will raise exception
    - atoi will need to use integer
    - `#inlcude <string>`

### Convert number to string
```cpp=
std::string str = std::to_string(num);
```

## Treat string 
### Find_\*_of
- String method
    1. `find_first_of`, `find_first_not_of`
    2. `find_last_of`, `find_last_not_of`
- If not found -> return `string::npos`
```cpp=
string str = "qwer qdfskjdgf bqewhb qkjv 12341";
string::size_t a = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
if (a != string::npos){
    cout << "Hello, I found number at " << a;
}
```
### Find method
- return `string::npos` if not found
- diff with `string::find_first_of`
    - need all matched to the searching string
### 字串內轉數字
- 在iterate 的途中變換
    - ex. 24941--Uncompress text
    ```cpp=
    for (int i=0; i<tmp.length(); i++){
        // turn word
        if ( i<tmp.length() && isalpha(tmp[i]) ){
            string word = "";
            while ( isalpha(tmp[i]) ){
                word += tmp[i++];
            }
        }
        // turn number
        if ( i<tmp.length() && isdigit(tmp[i]) ){
            int v = 0;
            while ( isdigit(tmp[i]) ){
                v = v * 10 + tmp[i++] - '0';
            }
        }
        if ( i<tmp.length() && !isalnum(tmp[i]) ){
            // pass...
        }
    }
    ```


## Sort and Find
- `log(n) + 1` (on sorted array)
    - use `upper_bound` (>) and `lower_bound` (>=)
    - included in `algorithm`
    - use `iterator` to catch the output
        - it will return the position
        - way to find the index
        ```cpp=
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), val);
        cout << it - v.begin() << endl; // output the index
        ```
        
## Number Theory
### Euclidean Algorithm
- for divisor and dividend
    - let a: dividend, b: divisor
```cpp=
int a, b, t;
cin >> a >> b; // need a >= b
while (b != 0){
    t = b;
    b = a % b;
    a = t;
}
printf ("GCD: %d", t);
```

## Judgement
### <cctype>
- isalpha
- isalnum
    - '!=0': true
    - '==0': false
- islower
- isupper



## 函式庫
```
<bits/stdc++.h>
iostream
cmath
cstdio
cstring
climits
cctype
string //getline, to_string...
utility
vector
map
set
unordered_map
algorithm
sstring
...
```