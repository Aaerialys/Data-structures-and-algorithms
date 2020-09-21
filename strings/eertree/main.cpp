#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define hashmap gp_hash_table
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i++)
#define ford(i,a,b) for(__typeof(a) i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define P2(x) (1LL<<(x))
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(int x) const { return x ^ SEED; }};

const int N=100010,M=1e9+7,V=27;
string in;
struct node{
    int len,ins[V],link,oc,l,r;
};
class eertree{
public:
    node tree[N];
    int sz,next,last;
    eertree(){
        tree[0].len=0; tree[0].link=1; tree[1].len=-1; tree[1].link=0; sz=2;
    }
    void ins(int pos){
        int ch=in[pos]-'A';
        while(in[pos-tree[last].len-1]!=in[pos]) last=tree[last].link;
        next=tree[last].link;
        while(in[pos-tree[next].len-1]!=in[pos]) next=tree[next].link;
        if(!tree[last].ins[ch]){
            tree[sz].len=tree[last].len+2; tree[sz].link=tree[next].ins[ch];
            tree[last].ins[ch]=sz;
            sz++;
        }
        last=tree[last].ins[ch];
        tree[last].oc++; tree[last].r=pos; tree[last].l=pos-tree[last].len+1;
    }
    void pnum(){
        ford(i,sz-1,2) tree[tree[i].link].oc+=tree[i].oc;
    }
};
eertree et;
int t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>t>>in;
    fori(0,in.size()) et.ins(i);
    et.pnum(); t=0;
    fori(2,N) t=max(t,et.tree[i].len);
    fori(2,N)
        if(et.tree[i].len==t){
            cout<<in.substr(et.tree[i].l,t)<<"\n"<<t;
            return 0;
        }
    return 0;
}
/**

*/
