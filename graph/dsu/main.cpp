#include <bits/stdc++.h>

using namespace std;

const int N=1000;
struct DSU{
    int p[N];
    DSU(){fill(all(p),-1);}
    int head(int x){return p[x]<0? x: p[x]=head(p[x]);}
    bool link(int x,int y){
        x=head(x); y=head(y);
        if(x==y) return 0;
        if(p[x]>p[y]) swap(x,y);
        p[x]+=p[y]; p[y]=x;
        return 1;
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    return 0;
}
