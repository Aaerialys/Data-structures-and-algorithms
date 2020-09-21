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
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};
#define nl "\n"

const int N=1000,M=MOD;
int n,m,a,b,c,d,e,s,t,lvl[N],nxt[N];
struct edge{
    int to,ind,flow,cap;
};
vector<edge> gr[N];
bool bfs(){
    seto(lvl,-1); seto(nxt,0);
    queue<int> toV; toV.push(s); lvl[s]=0;
    while(sz(toV)){
        int v=toV.front(); toV.pop();
        for(auto i:gr[v]) if(lvl[i.to]==-1&&i.flow<i.cap){
            toV.push(i.to); lvl[i.to]=lvl[v]+1;
        }
    }
    return lvl[t]>=0;
}
int dfs(int v,int flow){
    if(v==t) return flow;
    for(;nxt[v]<sz(gr[v]);nxt[v]++){
        auto &i=gr[v][nxt[v]];
        if(lvl[i.to]!=lvl[v]+1||i.flow==i.cap) continue;
        int f=dfs(i.to,min(flow,i.cap-i.flow));
        if(f){
            i.flow+=f; gr[i.to][i.ind].flow-=f;
            return f;
        }
    }
    return 0;
}
int maxFlow(){
    int ret=0;
    while(bfs()){
        int f=dfs(s,inf);
        while(f){
            ret+=f;
            f=dfs(s,inf);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m;
    fori(0,m){
        cin>>a>>b>>c; d=sz(gr[a]); e=sz(gr[b]);
        gr[a].pb({b,e,0,c}); gr[b].pb({a,d,0,0});
    }
    cin>>s>>t;
    cout<<maxFlow();
    return 0;
}
/**
6 9
0 1 10
0 3 10
1 2 4
1 3 2
1 4 8
2 5 10
3 4 9
4 2 6
4 5 10
0 5
*/
