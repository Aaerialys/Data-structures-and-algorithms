#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,a,b,c,x,y,v;deque<int> toV;
    cin>>V>>E;
    vector<pair<int,int>> gr[V];
    int dist[V],qNumb[V]={0};
    bool inQ[V]={false};
    fori(0,E)
    {
        cin>>a>>b>>c;
        a--;b--;
        gr[a].push_back({b,c});gr[b].push_back({a,c});
    }
    x=0;
    fori(0,V)
        dist[i]=INT_MAX;
    dist[x]=0;
    toV.push_back(x);
    c=0;
    while(!toV.empty())
    {
        v=toV.front();
        toV.pop_front();
        c-=dist[v];
        inQ[v]=false;
        if(qNumb[v]>V)
            break;
        fori(0,gr[v].size())
        {
            a=gr[v][i].first; b=gr[v][i].second;
            if(dist[a]>dist[v]+b)
            {
                dist[a]=dist[v]+b;
                if(!inQ[a])
                {
                    toV.push_back(a); //regular
                    //!toV.empty()&&dist[a]<dist[toV.front()]?toV.push_front(a):toV.push_back(a); //small lable first
                    //!toV.empty()&&dist[a]<c/toV.size()?toV.push_front(a):toV.push_back(a);
                    c+=dist[v];
                    inQ[a]=true;
                    qNumb[a]++;
                }
            }
        }
    }
    fori(0,V)
        cout<<(dist[i]==INT_MAX?-1:dist[i])<<"\n";
    return 0;
}
