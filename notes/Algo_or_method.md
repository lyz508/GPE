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
string BigAdd(string n1, string n2){
    if (n1.size() < n2.size()){
        string tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    for (int i=n2.size()-1, j=n1.size()-1; i>=0; i--, j--){
        n1[j] = n1[j] + (n2[i]-'0');
    }

    for (int i=n1.size()-1; i>0; i--){
        if (n1[i] > '9'){
            n1[i-1] += (n1[i]-'0')/10;
            n1[i] = '0'+(n1[i]-'0')%10;
        }
    }

    if (n1[0] > '9'){
        n1[0] = '0'+(n1[0]-'0')%10;
        n1 = '1'+n1;
    }
    
    return n1;
}
```
### 大數乘法
```cpp=
string BigMulti(string n1, string n2){
    vector<int> sum(n1.size()+n2.size()+3, 0);
    if (n1.size() < n2.size()){
        string tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    for (int i=n2.size()-1; i>=0; i--){
        for (int j=n1.size()-1; j>=0; j--){
            sum[(n2.size()-1-i)+(n1.size()-1-j)] += 
                (n1[j]-'0') * (n2[i]-'0');
        }
    }

    for (int i=0; i<sum.size()-1; i++){
        if (sum[i] > 9){
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
    }

    // erase 0
    reverse(sum.begin(), sum.end());
    while (sum.size() > 0 && sum[0] == 0)
        sum.erase(sum.begin());
    // judge 0
    if (sum.size() == 0)
        sum.push_back(0);

    return toString(sum);
}
```


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

## KnapSack Problem (背包問題)
- Classification
    1. 0/1 Knapsack Problem

### Implementation
```cpp=
/* KnapSack Problem:
 *  find largest weight can be put into knapsack
 * w_sum: all weight sum
 * n: total number of items
 * value: array of value
 * weight: array of weight
 * cost: array recording height value of current weight; Length: sum+1 */

void KnapSack(){
    for (int i=0; i<n; i++){
        for (int j=w_sum; j>=weight[i]; j--){
            cost[j] = max(
                cost[j], 
                cost[j - weight[i]] + value[i]
            );
        }
    }

    printf("Heighest value: %d", cost[w_sum]);
}
```
```cpp=
/* KnapSack Problem:
 *  1. find largest weight can be put into knapsack
 *  2. give one combination of largest situation
 * w_sum: all weight sum
 * n: total number of items
 * value: array of value
 * weight: array of weight
 * cost: array recording height value of current weight; Length: sum+1 
 * record: bool array, record if item can be put in that weight
 */

void KnapSack(){
    for (int i=0; i<n; i++){
        for (int j=w_sum; j>=weight[i]; j--){
            if (cost[j - weight[i]] + value[i] > cost[j]){
                cost[j] = cost[j - weight[i]] + value[i];
                record[i][j] = true;
            }
        }
    }

    // print out item
    for (int i=n-1, j=w_sum; i>=0; i--){
        if (record[i][j]){
            printf("Have %dth item\n", i);
            j -= weight[i];
        }
    }
    printf("Heighest value: %d", cost[w_sum]);
}

```





## KMP Algorithm 
- Objective: 在字串內尋找特定字串第一次出現位置
- 思想: dp 先處理next 問題(failure function 從哪裡繼續開始找)
### next table
```cpp=
vector< int > next_table;
void findNext(string str){
    next_table.resize(str.length());
    next_table[0] = 0; // first start with 0
    for (int i=1; i<str.length(); i++){
        int j=next_table[i-1];

        // if not equal, back to formor next 
        // (continue at previous equal position)
        while (j>0 && str[i] != str[j])
            j = next_table[j-1];

        // if equal -> add length,
        // it not equal && go back to start pos -> len = 0
        if (str[i] == str[j])
            next_table[i] = j+1;
        else    
            next_table[i] = 0;
    }

    printf("Partial Next Table: ");
    for (int i=0; i<str.length(); i++)
        printf("%d ", next_table[i]);
}
```
### KMP search
```cpp=
void KMP(string str, string target){
    int str_len = str.length(),
        target_len = target.length(),
        p = 0, s = 0;
    while ( p<target_len && s < str_len ){
        if (target[p] == str[s]){
            p++; 
            s++;
        }
        else{
            if (p == 0)
                s++;
            else
                p = next_table[p-1]; // search from previous corresponding
        }
    }
    if (p == 0 || p != target_len)
        printf("Not found !\n");
    else
        printf("From %d to %d\n", s-target_len, s-1);
}
```

## Bellman Ford
```cpp=
// Bellman Ford(SPFA)
// s: start
// es: edges
// ns: nodes

ns[s] = 0;
for (int t=0; t<n; t++){
    for (int i=0; i<es.size(); i++){
        u = es[i].u;
        v = es[i].v;
        if (ns[v] > ns[u] + es[i].w)
            ns[v] = ns[u] + es[i].w;
    }
}
```
- 10602 Longest Path

## LCS Longest Common Subsequence
- LIS 前身
- 實作方便，空出兩個sequence 前面第一位
- 遞迴判斷式
  - 相同 -> 為i-1, j-1 + 1 (都不選的len 長度 -> 此次len 長度)
  - 不相同 -> 為 i-1 j, i j-1 取max (不選其中一個字串的最大值)
```cpp=
string s1, s2;

void LCS(){
    vector< vector<int> > len(s1.size(), vector<int>(s2.size(), 0));

    for (int i=1; i<s1.size(); i++){
        for (int j=1; j<s2.size(); j++){
            if (s1[i] == s2[j])
                len[i][j] = len[i-1][j-1] + 1;
            else
                len[i][j] = max(len[i-1][j], len[i][j-1]);
        }
    }

    // longest length
    printf("%d\n", len[s1.size()-1][s2.size()-1]);
}
```


## LIS Longest Increasing Subsequence
```cpp=
/* LIS: Longest Increasing Subsequence
 * len: record IS length
 * prev: record last pos
 * print out: find longest, by prev to print out
 */
void LIS(vector<int> seq){
    int longest, pos;
    vector<int> len = vector<int>(seq.size(), 1), // initial, all have len = 1
                prev = vector<int>(seq.size(), -1),
                output;

    // dp len
    for (int i=0; i<seq.size(); i++){
        for (int j=i+1; j<seq.size(); j++){
            if (seq[i] < seq[j] && len[i] + 1 > len[j]){
                len[j] = len[i] + 1;
                prev[j] = i;
            }
        }
    }

    // find longest
    longest = len[0];
    pos = 0;
    for (int i=1; i<seq.size(); i++){
        if (len[i] > longest){
            longest = len[i];
            pos = i;
        }
    }

    // print out
    printf("Longest Increasing Subsequence: ");
    while (true){
        output.push_back(seq[pos]);
        if (prev[pos] == -1)
            break;
        pos = prev[pos];
    };
    reverse(output.begin(), output.end());
    for (int i: output)
        printf("%d ", i);
}
```

### BackTracking To find all LIS

## DP Dynamic Programming
### 區間DP


- `10603` Cutting Sticks


## Setting Value
### INF -> 0x3f3f3f3f
```
int inf = 0x3f3f3f3f;
```
