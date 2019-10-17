### 线段树：求一段区间和，可以任意修改某个下标的值 修改复杂度log(n),求区间和复杂度log(n) 
##注意：此模板下标从1开始
#include <iostream>
using namespace std;
const int maxn = 1e6+10;

int arr[] = {0,1,3,5,7,9,11};
int tree[maxn];
int sz = 6;

int build(int id,int s,int e){
    if(s == e){
        tree[id] = arr[s];
    }else{
        int mid = (s+e)/2,idl = 2*id,idr = 2*id+1;
        int suml = build(idl,s,mid);
        int sumr = build(idr,mid+1,e);
        tree[id] = suml+sumr;
    }
    return tree[id];
}

int query(int id,int s,int e,int l,int r){
    if(e<l || s>r) return 0;
    else if(s == l && e == r){
        return tree[id];
    }else{
        int mid = (s+e)/2,idl = 2*id,idr = 2*id+1;
        int suml = query(idl,s,mid,l,mid);
        int sumr = query(idr,mid+1,e,mid+1,e);
        return suml+sumr;
    }
}

void update(int id,int s,int e,int idx,int val){
    int mid = (s+e)/2,idl = 2*id,idr = 2*id+1;
    if(s == e) tree[id] = val;
    else{
        if(idx<=mid) update(idl,s,mid,idx,val);
        else update(idr,mid+1,e,idx,val);
        tree[id] = tree[idl]+tree[idr];
    }
}

int main(){
    build(1,1,6);
    for(int i = 1;i<=16;i++) printf("%3d",tree[i]);puts("");
    cout<<query(1,1,6,3,6)<<endl;
    update(1,1,6,5,6);
    for(int i = 1;i<=16;i++) printf("%3d",tree[i]);puts("");
    cout<<query(1,1,6,3,6);
    return 0;
}
