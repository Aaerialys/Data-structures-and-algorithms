#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct node
{
    int lc,rc,v;
};

const int N=3e5+1;
int sz;
node seg[22000000];

class segTree
{
public:
    segTree()
    {
        build();
    }
    void build()
    {
        seg[1]={0,0,0,0};
    }
    void update(ll pos,ll v)
    {
        update(pos,v,root,1,N);
    }
    void update(int pos,int v,int num,int l,int r)
    {
        seg[num].v+=v;
        if(l==pos&&r==pos)
            return;
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            if(seg[num].lc==0)
            {
                seg[num].lc=++sz;
                seg[sz]={0,0,0};
            }
            update(pos,m,b,seg[num].lc,l,mid);
        }
        if(pos>mid)
        {
            if(seg[num].rc==0)
            {
                seg[num].rc=++sz;
                seg[sz]={0,0,0};
            }
            update(pos,m,b,seg[num].rc,mid+1,r);
        }
    }
    int query(int le,int re)
    {
        return query(le,re,root,1,N);
    }
    int query(int le,int re,int num,int l,int r)
    {
        if(r==re&&l==le)
            return seg[num].v;
        int mid=(l+r)/2;
        if(le>mid)
            return seg[num].rc? query(le,re,seg[num].rc,mid+1,r): 0;
        if(re<=mid)
            return seg[num].lc? query(le,re,seg[num].lc,l,mid): 0;
        return (seg[num].lc? query(le,re,seg[num].lc,le,mid): 0)+(seg[num].rc? query(le,re,seg[num].rc,mid+1,re): 0);
    }
};

segTree st;
int n,q,a,b;
char ch;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fori(1,n+1)
    {
        cin>>a;
        st.update(i,a);
    }
    fori(0,q)
    {
        cin>>a>>b;
        cout<<st.query(a,b)<<"\n";
    }
    return 0;
}
