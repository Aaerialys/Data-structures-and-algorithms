#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=1000;

struct BITree{
    int bit[N];
    build(int arr[]){
        fori(1,N){
            bit[i]+=arr[i-1];
            bit[i+(i&(-i))]+=bit[i];
        }
    }
    void upd(int x,int v){
        for(;x<N;x+=x&-x) bit[x]+=v;
    }
    int query(int x){
        int ret=0;
        for(;x;x-=x&-x) ret+=bit[x];
        return ret;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
};
struct bitRange{
    biTree bit[2];
    void upd(int x,int val){
        bit[1].upd(1,val); bit[1].upd(x+1,-val);
        bit[0].upd(x+1,val*x);
    }
    void upd(int l,int r,int val){
        upd(l-1,-val); upd(r,val);
    }
    int query(int x){
        return bit[1].query(x)*x+bit[0].query(x);
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    fori(0,n)
    {
        cin>>a[i];
    }
    biTree b(a);
    fori(0,n)
    {
        cout<<b.get(i)<<" "<<b.addto(i)<<endl;
    }
    return 0;
}
