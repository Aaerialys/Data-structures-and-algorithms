#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,fma,mmx,popcnt,tune=native" //#pragma GCC optimize "prefetch-loop-arrays"
using namespace std; using namespace __gnu_pbds;
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define fori(a,b) foru(i,a,b)
#define forj(a,b) foru(j,a,b)
#define fork(a,b) foru(k,a,b)
#define seto(x,i) memset(x,i,sizeof x)
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define mt make_tuple
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define lwb lower_bound
#define upb upper_bound
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef int64_t i128; typedef uint64_t ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef long double lld; typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<class T1,class T2> using ordered_map=tree<T1,T2,less<T1>,rb_tree_tag,tree_order_statistics_node_update>; template<class T1> using ordered_set=ordered_map<T1,null_type>;
template<class T> using minpq=std::priority_queue<T,vector<T>,greater<T>>; template<class T> using maxpq=std::priority_queue<T,vector<T>,less<T>>;
template<class T> using minpairingheap=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>; template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,less<T>,pairing_heap_tag>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
const ll SEED=443214^chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); ll rand(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll fpow(ll a,ll b){ll ret=1;for(;b;b>>=1){if(b&1) ret=ret*a%MOD;a=a*a%MOD;}return ret;} ll fpow(ll a,ll b,ll M){ll ret=1;for(;b;b>>=1){if(b&1) ret=ret*a%M;a=a*a%M;}return ret;}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
template<class T1,class T2>constexpr bool ckmin(T1&x,const T2&y){return x>y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmin(T&x,const Ts&...xs){return ckmin(x,min(xs...));}
template<class T1,class T2>constexpr bool ckmax(T1&x,const T2&y){return x<y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmax(T&x,const Ts&...xs){return ckmax(x,max(xs...));}
template<class T,class U> void erase(T& t,const U& u){auto it=t.find(u);if(it!=end(t)) t.erase(it);}
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}};
void fIn(string s){freopen(s.c_str(),"r",stdin);} void fOut(string s){freopen(s.c_str(),"w",stdout);} void fIO(string s){fIn(s+".in"); fOut(s+".out");}
string to_string(char c){return string(1,c);} string to_string(char* s){return (string)s;} string to_string(string s){return s;}
template<class T> string to_string(complex<T> c){stringstream ss; ss<<c; return ss.str();}
template<class T1,class T2> string to_string(pair<T1,T2> p){return "("+to_string(p.pf)+","+to_string(p.ps)+")";}
template<class T> string to_string(T v){string ret="{"; for(const auto& x:v) ret+=to_string(x)+","; return ret+"}";}
void DBG(){cerr<<"]"<<endl;} template<class T,class... Ts> void DBG(T x,Ts... xs){cerr<<to_string(x); if(sizeof...(xs)) cerr<<", "; DBG(xs...);}
#ifdef LOCAL
    #define dbg(...) cerr<<"Line("<< __LINE__<<") -> ["<<#__VA_ARGS__<<"]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
#define nl "\n"

const int N=1e9,M=MOD;
struct Bitset{ //use pragma ofast and unroll loops for higher speed
    const static int B=P2(6),M=B-1,R=(N+M)/B,S=31-clz(B);
    const static ull MASK=-1;
    ull bit[R];
    struct BoolReference{
        ull *pos,bit;
        bool val;
        BoolReference(ull *_pos,int _ind,bool _val){
            pos=_pos; bit=P2(_ind); val=_val;
        }
        void update(){
            if(val) *pos|=bit;
            else *pos&=MASK^bit;
        }
        operator bool() const{
            return val;
        }
        bool operator=(bool x){
            val=x;
            update();
            return x;
        }
        bool operator=(BoolReference x){
            return operator=(bool(x));
        }
        void operator&=(bool x){
            val&=x;
            update();
        }
        void operator&=(BoolReference x){
            operator&=(bool(x));
        }
        void operator|=(bool x){
            val|=x;
            update();
        }
        void operator|=(BoolReference x){
            operator|=(bool(x));
        }
        void operator^=(bool x){
            val^=x;
            update();
        }
        void operator^=(BoolReference x){
            operator^=(bool(x));
        }
    };
    Bitset(){
        seto(bit,0);
    }
    Bitset(string s){
        seto(bit,0);
        fori(0,sz(s)) bit[i>>S]|=ll(s[i]-'0')<<(i&M);
    }
    Bitset(const Bitset &x){
        fori(0,x.R) bit[i]=x.bit[i];
    }
    string to_string(){
        string ret; ret.reserve(N);
        fori(0,N) ret+=(bit[i>>S]&P2(i&M)? '1': '0');
        return ret;
    }
    BoolReference operator[] (size_t x){
        return BoolReference(bit+(x>>S),x&M,bit[x>>S]&P2(x&M));
    }
    Bitset& operator=(const Bitset &x){
        fori(0,R) bit[i]=x.bit[i];
        return *this;
    }
    Bitset& operator^=(const Bitset &x){
        fori(0,R) bit[i]^=x.bit[i];
        return *this;
    }
    Bitset operator^(const Bitset &x){
        Bitset ret(*this);
        ret^=x;
        return ret;
    }
    Bitset& operator|=(const Bitset &x){
        fori(0,R) bit[i]|=x.bit[i];
        return *this;
    }
    Bitset operator|(const Bitset &x){
        Bitset ret(*this);
        ret|=x;
        return ret;
    }
    Bitset& operator&=(const Bitset &x){
        fori(0,R) bit[i]&=x.bit[i];
        return *this;
    }
    Bitset operator&(const Bitset &x){
        Bitset ret(*this);
        ret&=x;
        return ret;
    }
    Bitset& operator<<=(const int x){
        int sa=x>>S,sb=x&M,sc=B-sb;
        if(sb) ford(i,R,sa+1) bit[i]=bit[i-sa]<<sb|bit[i-sa-1]>>sc;
        else ford(i,R,sa+1) bit[i]=bit[i-sa];
        bit[sa]=bit[0]<<sb;
        bit[R-1]&=MASK>>(R*B-N);
        ford(i,sa,0) bit[i]=0;
        return *this;
    }
    Bitset operator<<(const int &x){
        Bitset ret(*this);
        ret<<=x;
        return ret;
    }
    Bitset& operator>>=(const int x){
        int sa=x>>S,sb=x&M,sc=B-sb;
        if(sb) fori(0,R-sa-1) bit[i]=bit[i+sa]>>sb|bit[i-sa+1]<<sc;
        else fori(0,R-sa-1) bit[i]=bit[i+sa];
        bit[R-sa-1]=bit[R-1]>>sb;
        fori(R-sa,R) bit[i]=0;
        return *this;
    }
    Bitset operator>>(const int &x){
        Bitset ret(*this);
        ret>>=x;
        return ret;
    }
    bool operator==(const Bitset &x){
        fori(0,R) if(bit[i]!=x.bit[i]) return 1;
        return 0;
    }
    bool operator!=(const Bitset &x){
        fori(0,R) if(bit[i]!=x.bit[i]) return 0;
        return 1;
    }
    int findNext(int x){ //including x
        if(bit[x>>S]>>(x&M)) return x+ctzll(bit[x>>S]>>(x&M));
        fori(x/B+1,R) if(bit[i]) return i*B+ctzll(bit[i]);
        return N;
    }
    int findPrev(int x){//including x
        if(bit[x>>S]<<M-(x&M)) return x-clzll(bit[x>>S]<<M-(x&M));
        ford(i,x/B,0) if(bit[i]) return i*B+M-clzll(bit[i]);
        return -1;
    }
    int findFirst(){return findNext(0);}
    int findLast(){return findPrev(N-1);}
    bool none(){return findFirst()==N;}
    bool any(){return !none();}
    int count(int l,int r){
        if(l>>S==r>>S) return popcountll(bit[l>>S]&MASK<<(l&M)&MASK>>M-(r&M));
        int ret=0,lb=l/B+1,rb=r/B;
        fori(lb,rb) ret+=popcountll(bit[i]);
        ret+=popcountll(bit[l>>S]&MASK<<(l&M));
        ret+=popcountll(bit[r>>S]^=MASK>>M-(r&M));
        return ret;
    }
    int count(){
        int ret=0;
        fori(0,R) ret+=popcountll(bit[i]);
        return ret;
    }
    void set(int l,int r,bool v){
        if(v){
            if(l>>S==r>>S){
                bit[l>>S]|=MASK<<(l&M)&MASK>>M-(r&M);
                return;
            }
            int lb=l/B+1,rb=r/B;
            fori(lb,rb) bit[i]=MASK;
            bit[l>>S]|=MASK<<(l&M);
            bit[r>>S]|=MASK>>M-(r&M);
        }
        else{
            if(l>>S==r>>S){
                bit[l>>S]&=MASK^(MASK<<(l&M)&MASK>>M-(r&M));
                return;
            }
            int lb=l/B+1,rb=r/B;
            fori(lb,rb) bit[i]=0;
            bit[l>>S]&=MASK^(MASK<<(l&M));
            bit[r>>S]&=MASK^(MASK>>M-(r&M));
        }
    }
    void set(int x,int v){set(x,x,v);}
    void set(int v){set(0,N-1,v);}
    void flip(int l,int r){
        if(l>>S==r>>S){
            bit[l>>S]^=MASK<<(l&M)&MASK>>M-(r&M);
            return;
        }
        int lb=l/B+1,rb=r/B;
        fori(lb,rb) bit[i]^=MASK;
        bit[l>>S]^=MASK<<(l&M);
        bit[r>>S]^=MASK>>M-(r&M);
    }
    void flip(int x){flip(x,x);}
    void flip(){flip(0,N-1);}
};
int n,q;
Bitset bs;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}
/**
to implement:
 reverse(l,r)
 > < <= >= (right is most significant for bitset, but it should be left significant for strings)
replace / and % with bitwise

bitset practice:
https://dmoj.ca/problem/btoi19p2
https://dmoj.ca/problem/mnyc17p6
https://dmoj.ca/problem/dmopc15c6p6
other verification:
https://dmoj.ca/problem/ucc20p1
https://dmoj.ca/problem/cco20p4
*/
