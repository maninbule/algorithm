## 双哈希
#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e6+10;

int pr1 = 163,pr2 = 131,mod1 = 9905411,mod2 = 1000000007;
ull h1[maxn],H1[maxn],h2[maxn],H2[maxn],len1,len2;
ull p1[maxn],p2[maxn];
int N;
string s,res;

ull get1(int l,int r,ull h[],ull p[]){ //闭区间
    return (h[r] - (h[l-1]*p[r-l+1])%mod1+mod1)%mod1;
}
ull get2(int l,int r,ull h[],ull p[]){
    return (h[r] - (h[l-1]*p[r-l+1])%mod2+mod2)%mod2;
}

void init(){ //初始化
    p1[0] = 1;p2[0] = 1;
    for(int i = 1;i<maxn;i++){
        p1[i] = p1[i-1]*pr1%mod1;
        p2[i] = p2[i-1]*pr2%mod2;
    }
}

int main(){
    init();
  
    if(get1(l,r,h1,p1) == get1(l,r,h2,p1) && get2(l,r,H1,p2) == get2(l,r,H2,p2)) // 哈希匹配
    return 0;
}
