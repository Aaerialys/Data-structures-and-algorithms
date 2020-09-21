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

const int N=500001,M=1e9+7;
typedef struct node* tr; //tr=treap
struct node{
    int v,p; tr c[2];
    int sz,s,lz;
    bool flip;
    node(int val){
        v=s=val; p=randint(0,1e9);
        c[0]=c[1]=nullptr; sz=1; lz=inf; flip=false;
    }
    void upd(int val){
        v=lz=val; s=val*sz;
    }
    friend int Sz(tr x){return x?x->sz:0;}
    friend int S(tr x){return x?x->s:0;}
    void push(){
        if(flip){
            swap(c[0],c[1]);
            flip=0;
            fori(0,2) c[i]->flip^=1;
        }
        if(lz!=inf){
            fori(0,2) if(c[i]) c[i]->upd(lz);
            lz=inf;
        }
    }
    void pull(){
        sz=1+Sz(c[0])+Sz(c[1]);
        s=v+S(c[0])+S(c[1]);
    }
    friend tr push(tr x){if(x) x->push(); return x;}
    friend tr pull(tr x){if(x) x->pull(); return x;}
};
pair<tr,tr> split(tr cur,int v){ //nodes >=v to right
    if(!cur) return{cur,cur};
    push(cur);
    if(cur->v>=v){
        auto temp=split(cur->c[0],v); cur->c[0]=temp.ps;
        return {temp.pf,pull(cur)};
    }
    auto temp=split(cur->c[1],v); cur->c[1]=temp.pf;
    return {pull(cur),temp.ps};
}
pair<tr,tr> isplit(tr cur,int ind){ //first ind nodes go left
    if(!cur) return{cur,cur};
    push(cur);
    if(Sz(cur->c[0])>=ind){
        auto temp=isplit(cur->c[0],ind); cur->c[0]=temp.ps;
        return {temp.pf,pull(cur)};
    }
    else{
        auto temp=isplit(cur->c[1],ind-Sz(cur->c[0])-1); cur->c[1]=temp.pf;
        return {pull(cur),temp.ps};
    }
}
tr merge(tr l,tr r){
    if(!l||!r) return (l?pull(l):pull(r));
    push(l); push(r);
    if(l->p>r->p){
        l->c[1]=merge(l->c[1],r);
        return pull(l);
    }
    r->c[0]=merge(l,r->c[0]);
    return pull(r);
}
tr ins(tr cur,int v){
    auto a=split(cur,v),b=split(a.ps,v+1);
    return merge(a.pf,merge(new node(v),b.ps));
}
tr del(tr cur,int v){
    auto a=split(cur,v),b=split(a.ps,v+1);
    return merge(a.pf,b.ps);
}
void del(tr cur){
    if(!cur) return;
    fori(0,2) del(cur->c[i]);
    delete cur;
}
void tour(tr cur){
    if(!cur) return;
    push(cur); tour(cur->c[0]); tour(cur->c[1]); cout<<cur->v<<" ";
}
int n,q,a,b,c,d;
string in;
tr rt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(1,n+1){
        cin>>a;
        rt=merge(rt,new node(a));
    }
    while(q--){
        cin>>in;
        if(in=="INSERT"){
            cin>>a>>b; auto x=isplit(rt,a);
            fori(0,b){
                cin>>c;
                x.pf=merge(x.pf,new node(c));
            }
            rt=merge(x.pf,x.ps);
        }
        if(in=="DELETE"){
            cin>>a>>b;
            auto x=isplit(rt,a-1),y=isplit(x.ps,b);
            del(y.pf);
            rt=merge(x.pf,y.ps);
        }
        if(in=="MAKE-SAME"){
            cin>>a>>b>>c;
            auto x=isplit(rt,a-1),y=isplit(x.ps,b);
            y.pf->upd(c);
            rt=merge(x.pf,merge(y.pf,y.ps));
        }
        if(in=="REVERSE"){
            cin>>a>>b;
            auto x=isplit(rt,a-1),y=isplit(x.ps,b);
            y.pf->flip^=1;
            rt=merge(x.pf,merge(y.pf,y.ps));
        }
        if(in=="GET-SUM"){
            cin>>a>>b;
            auto x=isplit(rt,a-1); auto y=isplit(x.ps,b);
            cout<<S(y.pf)<<"\n";
            rt=merge(x.pf,merge(y.pf,y.ps));
        }
    }
    return 0;
}
/**

*/
