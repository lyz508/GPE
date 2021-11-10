# Algo or method
## 快速冪
- $O(lg n)$ 算 $n^n$
### Implementation
```cpp=
// faster power
int fp(int n, int p){
    if (p == 1) // end condition
        return n;

    int rtn, cp;
    if ( p%2 == 0 ){ // even
        cp = fp(n, p/2);
        rtn = cp * cp;
    }
    else{ // odd
        cp = fp(n, (p-1)/2);
        rtn = n * cp * cp;
    }

    return rtn;
}
```

### Example
1. 10416 Last digit

## 字串處理
- 轉數字
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

### Example
1. 24941 Uncompress text

## 卡特蘭數 (Catalan Number)
- 括號匹配、標準young 表，出棧序列、Dyck Words、找零錢、筆畫群峰...
- 二叉樹數量，不相交弦問題...
- 為比自身小的子問題集合而成
- 以不合法路徑做理解。
```
序列數
1 , 1 , 2 , 5 , 14 , 42 , 132 , 429 , 1430 , 4862 , 16796 , 58786 , 208012 , 742900 , 2674440 , 9694845 , 35357670 , 129644790
```
```
Definition
fn=f0∗fn−1+f1∗fn−2+…+fn−1*f0
```

### Implementation (Build table)
```cpp=
void catalen(){
    dp[0] = 1;
    dp[1] = 1;
    for (int n=2; n<=20; n++){
        // from Cn-1C_0 to C_0Cn-1
        for (int i=0; i<n; i++){
            dp[n] += dp[i]*dp[n-1-i];
        }
    }
}
```

### Example
1. 10501 Safe Salutations (不相交弦問題)
2. 10605 Count the Tree (二叉樹數目問題)


## 大數
### 大數加法
```cpp=
string BigMulti(string s1, string s2){
    string res = "";
    vector< int > n1, n2, sum, tmp;

    for (int i=0; i<s1.length(); i++)
        n1.push_back(s1[i] - '0');
    for (int i=0; i<s2.length(); i++)
        n2.push_back(s2[i] - '0');
    sum.resize(n1.size() + n2.size() + 1);

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    // switch
    if (n1.size() < n2.size()){
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    // multi
    for (int i=0; i<n2.size(); i++){
        for (int j=0; j<n1.size(); j++){
            sum[i+j] += n2[i]*n1[j];
        }
    }

    // carry
    for (int i=0; i<sum.size(); i++){
        if (sum[i] >= 10){
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
    }

    // output
    bool f = false;
    for (int i=sum.size()-1; i>=0; i--){
        if (!f){
            if (sum[i] != 0)
                f = true;
        }
        if (f){
            res += '0' + sum[i];
        }
    }

    return res;
}
```
### 大數乘法
```cpp=

string BigAdd(string s1, string s2){
    vector< int > n1, n2, sum, tmp;
    string res = "";
    bool f = false;

    for (int i=0; i<s1.length(); i++)
        n1.push_back(s1[i] - '0');
    for (int i=0; i<s2.length(); i++)
        n2.push_back(s2[i] - '0');

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());


    // switch
    if (n1.size() < n2.size()){
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    sum.resize(n1.size() + 10);


    // add
    for (int i=0, t; i<sum.size()-1; i++){
        // for (int i=0; i<n1.size(); i++){
        //     printf("%d", n1[i]);
        // }
        // printf("\n");
        // for (int i=0; i<n2.size(); i++){
        //     printf("%d", n2[i]);
        // }
        // printf("\n");
        // for (int i=0; i<sum.size(); i++){
        //     printf("%d", sum[i]);
        // }
        // printf("\n");


        if (i < n2.size()){
            t = n1[i] + n2[i] + sum[i];
            sum[i] = t % 10;
            sum[i+1] += t / 10;
        }
        else if (i < n1.size()){
            sum[i+1] += n1[i] / 10;
            sum[i] += n1[i] % 10;
        }
        else{
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
    }

    for (int i=sum.size()-1; i>=0; i--){
        if (!f){
            if (sum[i] != 0)
                f = true;
        }
        if (f)
            res += '0' + sum[i];
    }


    return res;
}

```


## 階乘頭級

## 常用函式
### Algorithm
- sort
- reverse
- lower_bound(>=), upper_bound(>)

### Map
- find (with map<T, T>::iterator)

### string
- to_string (確認)
- find_*_of
- find
    - cant find -> return `string::npos`
- getline

### cstdio
- getchar
- sprintf
    - input: 加一個string
- printf
    - 注意格式
        - `%0*d`: 加兩變數，分別指定0的位數以及要輸出的數。

### sstream (stringstream)
- `<<` 導入
- `>>` 導出

### cstring
- strcmp
    - return 0: 相同
    - input: c_str

### cctype
- isdigit
- isalnum
- isalpha
- islower
- isupper
- tolower, toupper

### cmath
- max, min
- M_PI
- sqrt
- pow (用快速冪別用這個)

### utility
- pair<T, T>

### cfloat
- Constant: FLT_MIN


## 判斷完全平方
```cpp=
int j = sqrt(n);
if ( j*j == n )
    printf("yes\n");
else
    printf("no\n");
```

## KnapSack Problem
