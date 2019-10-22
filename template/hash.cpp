## 哈希出一个字符串的哈希数组，可以O(1)时间求出字符串某个闭区间[l,r]的值

typedef unsigned long long ull;
const int Pr = 131;
const int maxn = 1e6+10;//取131或者13331，mod取2^64==ull，所以直接利用溢出来自动取余
ull h[maxn],p[maxn];//字符串哈希值数组，P的幂数组
char s[maxn]; //or string

ull get(int l,int r){ //计算某个闭区间字符串的哈希值，下标从1开始
    return h[r] - h[l-1]*p[r-l+1];
}

void init(){ //计算字符串哈希，以及幂数组，注意：读取字符串从下标1开始存储
    p[0] = 1;
    for(ull i = 1;i<=N;i++){
        p[i] = p[i-1]*Pr;
        h[i] = h[i-1]*Pr + s[i-1];
    }
}

int main(){
  
  return 0;
}
