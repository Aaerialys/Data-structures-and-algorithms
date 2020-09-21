#include <bits/stdc++.h>

using namespace std;
int gr[5][5]=  {{0,1,0,0,0},
                {1,0,1,1,0},
                {0,1,0,1,0},
                {0,1,1,0,1},
                {0,0,0,1,0}};
typedef pair<int,int> pii;
int prim()/**adj list mst*/
{
    int V,E,a,b,c;
    typedef pair<int,int> pii;
    cin>>V>>E;
    vector<pii> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        gr[a].push_back(make_pair(c,b)); gr[b].push_back(make_pair(c,a));
    }
    priority_queue<pii,vector<pii>,greater<pii> > toVisit;
    int v;
    int dist[V];
    int prev[V];
    fori(0,V)
        prev[i]=dist[i]=INT_MAX;
    dist[0]=0;
    toVisit.push(make_pair(0,0));
    while(toVisit.empty()==false)
    {
        v=toVisit.top().second;
        toVisit.pop();
        fori(0,gr[v].size())
        {
            if(dist[gr[v][i].second]>gr[v][i].first&&gr[v][i].second!=prev[v])
            {
                dist[gr[v][i].second]=gr[v][i].first;
                prev[gr[v][i].second]=v;
                toVisit.push(make_pair(dist[gr[v][i].second],gr[v][i].second));
            }
        }
    }
}
int dijkstra(int x,int y, int V)/**priority queue, adj list*/
{
    int V,E,x,a,b,c;
    typedef pair<int,int> pii;
    cin>>V>>E;
    vector<pii> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        gr[a].push_back(make_pair(c,b));
        gr[b].push_back(make_pair(c,a));
    }
    priority_queue<pii,vector<pii>,greater<pii> > toVisit;
    int v,u;
    int dist[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[x]=0;
    toVisit.push(make_pair(0,x));
    while(toVisit.empty()==false)
    {
        u=toVisit.top().first; v=toVisit.top().second;
        toVisit.pop();
        if(u>dist[v]) continue;
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i].second]>dist[v]+gr[v][i].first)
            {
                dist[gr[v][i].second]=dist[v]+gr[v][i].first;
                toVisit.push(make_pair(dist[gr[v][i].second],gr[v][i].second));
            }
        }
    }
}
void dijkstra() /*adj list, no queue*/
{
    int V,E,x=0,a,b,c;
    typedef pair<int,int> pii;
    cin>>V>>E;
    vector<pii> gr[V];
    for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
        gr[a].push_back(make_pair(c,b));
        gr[b].push_back(make_pair(c,a));
    }
    int v,m;
    int dist[V];
    bool visit[V]={false};
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[x]=0;
    for(int i=0;i<V;i++)
    {
        m=INT_MAX;
        for(int j=0;j<V;j++)
        {
            if(m>dist[j]&&visit[j]==false)
            {
                m=dist[j];
                v=j;
            }
        }
        visit[v]=true;
        for(int j=0;j<gr[v].size();j++)
        {
            if(dist[gr[v][j].second]>dist[v]+gr[v][j].first)
            {
                dist[gr[v][j].second]=dist[v]+gr[v][j].first;
            }
        }
    }
}
int bfs(int x,int y, int V)/*directional unweighted graph using adj matrix*/
{
    queue<int> toVisit;
    int dist[V];
    int v;
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[x]=0;
    toVisit.push(x);
    while(toVisit.empty()==false)
    {
        v=toVisit.front();
        toVisit.pop();
        for(int i=0;i<V;i++)
        {
            if(gr[v][i]==true&&dist[i]>dist[v]+1)
            {
                dist[i]=dist[v]+1;
                toVisit.push(i);
            }
        }
    }
    return dist[y];
}
int bfs(int x,int y, int V)/*directional unweighted graph using adj list*/
{
    queue<int> toVisit;
    int dist[V];
    int v;
    for(int i=0;i<V;i++)
        dist[i]=INT_MAX;
    toVisit.push(x);
    dist[x]=0;
    while(!toVisit.empty())
    {
        v=toVisit.front();
        toVisit.pop();
        for(int i=0;i<gr[v].size();i++)
        {
            if(dist[gr[v][i]]>dist[v]+1)
            {
                dist[gr[v][i]]=dist[v]+1;
                toVisit.push(gr[v][i]);
            }
        }
    }
    return dist[y];
}
void dfsR(int v,int dist[],int V)/*directional unweighted graph using adj matrix*/
{
    for(int i=0;i<V;i++)
    {
        if(gr[v][i]==true&&dist[i]>dist[v]+1)
        {
            dist[i]=dist[v]+1;
            dfsR(i,dist,V);
        }
    }
}
int dfs(int x,int y,int V)
{
    int dist[V];
    for(int i=0;i<V;i++)
        dist[i]=INT_MAX;
    dist[x]=0;
    dfsR(x,dist,V);
    return dist[y];
}
int topS(int V)
{
    int in[V]={0},c=0,v;
    queue <int> toV;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(gr[j][i]==1)
            {
                in[i]++;
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        if(in[i]==0)
        {
            toV.push(i);
        }
    }
    while(toV.empty()==false)
    {
        v=toV.front();
        toV.pop();
        c++;
        for(int i=0;i<V;i++)
        {
            if(gr[v][i]==1)
            {
                in[i]--;
                if(in[i]==0)
                {
                    toV.push(i);
                }
            }
        }
    }
    if(c!=V)
    {
        cout<<"cycle";
        return 1;
    }
    return 0;
}
int main()
{
    int V,x,y;
    cin>>V>>x>>y;
    cout<<bfs(x,y,V);
    cout<<dfs(x,y,V);
    /********************************/
    return 0;
}
