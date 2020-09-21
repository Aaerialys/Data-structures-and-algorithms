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
using namespace std;

const int N=5000;
int arr[N][N];

class biTree
{
    public:
    int tree[N][N];
    biTree()
    {
        fori(0,N)
            forj(0,N)
                tree[i][j]=0;
    }
    biTree(bool aa)
    {
        fori(0,n+1)
            forj(0,m+1)
                tree[i][j]=0;
        fori(1,n+1)
        {
            forj(1,m+1)
            {
                tree[i][j]+=arr[i-1][j-1];
                tree[i][j+(j&(-j))]+=tree[i][j];
            }
        }
        fori(1,m+1)
            forj(1,n+1)
                tree[j+(j&(-j))][i]+=tree[j][i];
    }
    void add(int x,int y,int v)
    {
        int y0;
        while(x<N)
        {
            y0=y;
            while(y0<N)
            {
                tree[x][y0]+=v;
                y0+=(y0&(-y0));
            }
            x+=(x&(-x));
        }
    }
    int addto(int x,int y)
    {
        int sum=0,y0;
        while(x>0)
        {
            y0=y;
            while(y0>0)
            {
                sum+=tree[x][y0];
                y0-=(y0&(-y0));
            }
            x-=(x&(-x));
        }
        return sum;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    return 0;
}
