#include <iostream>
#include <string>
using namespace std;

int T;
string s;
int main(){
    cin>>T;
    while(T--){
        cin>>s;
        long long  score = 0;int t = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == 'O') t++;
            else t = 0;
            score += t;
        }
        cout<<score<<endl;
    }

    return 0;
}
