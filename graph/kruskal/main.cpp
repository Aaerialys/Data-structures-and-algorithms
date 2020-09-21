#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
struct edge
{
    int a,b,c;
};
bool cmp(edge x,edge y)
{
    return x.c<y.c;
}
class djSet
{
private:
    int V;
    vector<int> parent;
public:
    djSet(int v)
    {
        V=v;
        parent.reserve(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
    }
    int lead(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=lead(parent[x]);
        }
        return parent[x];
    }
    void link(int x,int y)
    {
        x=lead(x);
        y=lead(y);
        parent[x]=y;
    }
};

int main()
{
    int V,E,x,y,z,t=0;
    cin>>V>>E;
    vector<edge> gr;
    vector<edge> mst;
    fori(0,E)
    {
        cin>>x>>y>>z;
        x--;
        y--;
        gr.push_back({x,y,z});
    }
    sort(gr.begin(),gr.end(),cmp);
    djSet djs(V);
    fori(0,E)
    {
        if(djs.lead(gr[i].a)!=djs.lead(gr[i].b))
        {
            mst.push_back(gr[i]);
            djs.link(gr[i].a,gr[i].b);
            t+=gr[i].c;
        }
    }
    cout<<t;
    return 0;
}
