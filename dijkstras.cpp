#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

void dijkstras(int src,int V,vector<vector<pair<int,int>>> &graph)
{
    vector<int> dist(V,INT_MAX);
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src]=0;
    pq.push({0,src});
    while (!pq.empty())
    {
        int u =pq.top().second;
        pq.pop();
        for(auto edge: graph[u])
        {
            int w = edge.first;
            int v = edge.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<dist.size();i++)
    {
        if(dist[i]==INT_MAX)
        {
            cout<<i<<" -> "<<" unreachable "<<endl;
        }
        cout<<i<<" -> "<<dist[i]<<endl;
    }
}
int main()
{
    int V,E;
    cout<<"enter the vertices and edges"<<endl;
    cin>>V>>E;
    vector<vector<pair<int,int>>> graph(V);
    cout<<"enter the u , v and w"<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({w,v});
    }
    cout<<"output: "<<endl;
    dijkstras(0,V,graph);
   
    return 0;
}