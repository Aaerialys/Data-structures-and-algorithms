#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a);i>=(b);i--)
#define fori(a,b) foru(i,a,b)
#define forj(a,b) foru(j,a,b)
#define fork(a,b) foru(k,a,b)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
template<typename T1,typename T2> using hashmap=gp_hash_table<T1,T2>;
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};

const int N=P2(17),M=1e9+7;
struct node{
    int v,lz;
};
class segTree{ //0 indexed
public:
    node seg[2*N];
    void pull(int num){
        seg[num].v=max(seg[num*2].v,seg[num*2+1].v);
    }
    void push(int num,int l,int r){
        if(!seg[num].lz) return;
        if(l!=r) fori(0,2) seg[2*num+i].lz+=seg[num].lz;
        seg[num].v+=seg[num].lz;
        seg[num].lz=0;
    }
    void build(int *arr){
        fori(0,N) seg[i+N].v=arr[i];
        ford(i,N-1,1) pull(i);
        fori(1,2*N) seg[i].lz=inf;
    }
    void upd(int lo,int hi,int val,int num=1,int l=0,int r=N-1){
        push(num,l,r);
        if(hi<l||r<lo) return;
        if(lo<=l&&r<=hi){
            seg[num].lz=val; push(num,l,r);
            return;
        }
        int mid=(l+r)/2;
        upd(lo,hi,val,num*2,l,mid); upd(lo,hi,val,num*2+1,mid+1,r);
        pull(num);
    }
    int query(int lo,int hi,int num=1,int l=0,int r=N-1){
        push(num,l,r);
        if(hi<l||r<lo) return -inf;
        if(lo<=l&&r<=hi) return seg[num].v;
        int mid=(l+r)/2;
        return max(query(lo,hi,num*2,l,mid),query(lo,hi,2*num+1,mid+1,r));
    }
};
segTree st;
int q,n,a,b,c,sz[N],in[N],rt[N],par[N];
vector<int> gr[N];
string s;

int szDfs(int v,int p){
    par[v]=p; sz[v]=1;
    for(auto& i:gr[v]) if(i!=p){
        sz[v]+=szDfs(i,v);
        if(gr[v][0]==p||sz[i]>sz[gr[v][0]]) swap(i,gr[v][0]);
    }
    return sz[v];
}
void hldDfs(int v,int p){
    in[v]=a++;
    for(auto i:gr[v]) if(i!=p){
        rt[i]=(i==gr[v][0]? rt[v]: i);
        hldDfs(i,v);
    }
}
void updPath(int u,int v,int val){
    while(rt[u]!=rt[v]){
        if(in[rt[u]]>in[rt[v]]) swap(u,v);
        st.upd(in[rt[v]],in[v],val);
        v=par[rt[v]];
    }
    if(in[u]>in[v]) swap(u,v);
    st.upd(in[u],in[v],val); //u for nodes, gr[u][0] for edges and return if u==v
}
int query(int u,int v){
    int ret=-inf;
    while(rt[u]!=rt[v]){
        if(in[rt[u]]>in[rt[v]]) swap(u,v);
        ret=max(ret,st.query(in[rt[v]],in[v]));
        v=par[rt[v]];
    }
    if(in[u]>in[v]) swap(u,v);
    ret=max(ret,st.query(in[u],in[v])); //u for nodes, gr[u][0] for edges and return if u==v
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(1,n){
        cin>>a>>b;
        gr[a].eb(b); gr[b].eb(a);
    }
    a=0; szDfs(1,0); hldDfs(1,0);
    cin>>q;
    while(q--){
        cin>>s>>a>>b;
        if(s=="add") st.upd(in[a],in[a]+sz[a]-1,b);
        else cout<<query(a,b)<<"\n";
    }
    return 0;
}
/**

*/
