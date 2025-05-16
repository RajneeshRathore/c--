#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void prims(int src,int V,vector<vector<pair<int,int>>>& adj)
{
    vector<bool> mst(V,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    mst[src]=true;
    pq.push({0,src});
    int cost=0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(auto edge:adj[u])
        {
            int w = edge.first;
            int v = edge.second;
            if(!mst[v])
            {
                mst[v]=true;
                cost+=w;
            }
        }
    }
    cout<<"the cost of an mst : "<<cost<<endl;
}
int main()
{
    cout<<"Enter the vertex and edge"<<endl;
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int,int>>> adj(V);
    cout<<"enter the u , v and w"<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
       adj[v].push_back({w,u});
    }
    prims(0,V,adj);
    return 0;
}