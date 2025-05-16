#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void bellman(int src,int V,vector<vector<pair<int,int>>>& graph)
{
   vector<int> dist(V,INT_MAX);
   dist[src]=0;
   for(int i=0;i<V-1;i++)
   {
     for(int u=0;u<V;u++)
     {
         for(auto edge :graph[u])
         {
             int v = edge.second;
             int w = edge.first;
             if(dist[v]>dist[u]+w)
             {
                dist[v]=dist[u]+w;
             }
         }
     }
   }
   for(int i=0;i<dist.size();i++)
   {
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
    bellman(0,V,graph);
    return 0;
}