#include <iostream>
#include <string>
#include <map>
using namespace std;
int T;
string s;
map<char,double> mp;
int main(){
    mp['C'] = 12.01;mp['H'] = 1.008;mp['O'] = 16.00;mp['N'] = 14.01;
    cin>>T;
    while(T--){
        cin>>s;
        double res = 0; int len = s.length();
        for(int i = 0;i<len;i++){
            if(isalpha(s[i])){ //判断一个字母之后的情况
                if(i+1>=len || isalpha(s[i+1])) res += mp[s[i]];
                else{
                    int t = 0,j = i+1;
                    while(j<len && isdigit(s[j])) t = t*10+s[j]-'0',j++;
                    res += mp[s[i]]*t;
                }
            }
        }
        printf("%.3f\n",res);
    }
    return 0;
}
