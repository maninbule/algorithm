#include <iostream>
#include <string>
#include <map>
using namespace std;

int T,N;
int main(){
    cin>>T;
    while(T--){
        map<int,int> mp;
        cin>>N;
        for(int i = 1;i<=N;i++){
            int t = i;
            while(t){ //取出每个数字的位，在map里面进行计数
                mp[t%10]++;
                t/=10;
            }
        }
        for(int i = 0;i<=9;i++) {
            printf("%d",mp[i]);
            if(i<9) printf(" ");
            if(i==9) puts("");
        }
    }
    return 0;
}
