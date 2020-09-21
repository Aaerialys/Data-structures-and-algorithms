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
    typedef long long i128; typedef long long ui128;
#endif
typedef long long ll; typedef int8_t byte; typedef long double lld;
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

const ll N=200010,V=27;
int n;
string in;
struct SuffixArray{
    string s;
    int n,rnk[N],sa[N],lcp[N];
    void genSa(string in){
        int shift=1,x;
        s=in; n=s.size();
        rnk[n]=-1; iota(sa,sa+n+1,0);
        sort(sa,sa+n,[&](int a,int b){return s[a]<s[b];});
        fori(0,n) rnk[sa[i]]=i&&s[sa[i]]==s[sa[i-1]]? rnk[sa[i-1]]: i;
        for(shift=1;shift<n;shift<<=1){
            int nex[n],temp[n]; iota(nex,nex+n,0); copy(sa,sa+n,temp);
            fori(-1,n){
                x=(i==-1? n: temp[i])-shift;
                if(x>=0) sa[nex[rnk[x]]++]=x;
            }
            copy(rnk,rnk+n,temp);
            fori(0,n)
                rnk[sa[i]]=i&&sa[i-1]+shift<n&&temp[sa[i]]==temp[sa[i-1]]&&temp[sa[i]+shift]==temp[sa[i-1]+shift]? rnk[sa[i-1]]: i;
        }
    }
    void genLcp(){
        int len=0;
        fori(0,n){
            if(rnk[i]==n-1){
                len=0;
                continue;
            }
            for(int j=sa[rnk[i]+1];i+len<n&&j+len<n&&s[i+len]==s[j+len];len++);
            lcp[rnk[i]]=len;
            if(len) len--;
        }
    }
};
SuffixArray sa;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>in; n=in.size();
    sa.genSa(in); sa.genLcp();
    cout<<*max_element(sa.lcp,sa.lcp+n);
    return 0;
}
/**
1 bbababb
*/
