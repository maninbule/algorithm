### 线段树：求一段区间和，可以任意修改某个下标的值 修改复杂度log(n),求区间和复杂度log(n) 
##注意：此模板下标从0开始
const int maxn = 1e6+10;
int tree[maxn];
vector<int> arr;
NumArray(vector<int>& nums) {
    arr = nums;
    if(nums.size()) build_tree(0,0,arr.size()-1);
}

int build_tree(int id,int s,int e){
    if(s == e){
        tree[id] = arr[s];
    }else{
        int mid = (s+e)/2,idl = 2*id+1,idr = 2*id+2;
        int suml = build_tree(idl,s,mid);
        int sumr = build_tree(idr,mid+1,e);
        tree[id] = suml+sumr;
    }
    return tree[id];
}

void modify(int id,int s,int e,int idx,int val){
    if(s == e){
        tree[id] = val;
    }else{
        int mid = (s+e)/2,idl = 2*id+1,idr = 2*id+2;
        if(idx<=mid) modify(idl,s,mid,idx,val);
        else  modify(idr,mid+1,e,idx,val);
        tree[id] = tree[idl]+tree[idr];
    }
}

int query(int id,int s,int e,int l,int r){
    if(r<s || l>e) return 0;
    else if(l<=s && e<=r){
        return tree[id];
    }else{
        int mid = (s+e)/2,idl = 2*id+1,idr = 2*id+2;
        int suml = query(idl,s,mid,l,r);
        int sumr = query(idr,mid+1,e,l,r);
        return suml+sumr;
    }
}

