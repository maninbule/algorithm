#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T;
string s;

vector<int> do_next(string s){ //next数组
    int len = s.length();
    vector<int> nx(len);
    for(int i = 1;i<len;i++){
        int j = nx[i-1];
        while(s[i] != s[j] && j>0) j = nx[j-1];
        if(s[i] == s[j]) j++;
        nx[i] = j;
    }
    return nx;
}

int main(){
    cin>>T;
    while(T--){
        cin>>s;
        auto nx = do_next(s);
        int last = nx[nx.size()-1];
        int len = s.length();
        if(len%(len-last) == 0) cout<<len-last<<endl; //kmp求最小循环节的公式
        else cout<<len<<endl;//未满整数个周期就按照没有周期来计算
        if(T) cout<<endl;
    }
    return 0;
}
