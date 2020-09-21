#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int x,y,d,ans[100];
void egcd(int a,int b)
{
    if(b==0)
    {
        x=1; y=0; d=a;
        return;
    }
    egcd(b,a%b);
    x-=a/b*y-y;
    y=x-y;
    x-=y;
}
int f(int a,int b,int m)
{
    egcd(a,m);
    if(b%d)
        return -1;
    x=x*(b/d)%m;
    fori(0,d)
        ans[i]=(x+i*m/d)%m;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    egcd(a,b);
    cout<<x<<"*"<<a<<"+"<<y<<"*"<<b<<"="<<ans;
    return 0;
}
