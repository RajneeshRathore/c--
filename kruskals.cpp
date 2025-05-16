#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Edge{
    int u,v,w;
}Edge;
int find(int x,vector<int> &parent)
{
    if(parent[x]==x)
    {
        return x;
    }
    return parent[x]=find(parent[x],parent);
}
void union_by_rank(int a,int b,vector<int>& parent,vector<int> &rank)
{
    int parU=find(a,parent);
    int parV=find(b,parent);
    if(rank[parU]==rank[parV])
    {
        parent[parV]=parU;
        rank[parU]++;
    }
    else if(rank[parU]>rank[parV])
    {
        parent[parV]=parU;
    }
    else
    {
        parent[parU]=parV;
    }
}
void kruskals(int V,vector<Edge>& edges)
{
    vector<int> parent(V);
    vector<int> rank(V,0);
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
    }
    sort(edges.begin(),edges.end(),[](Edge &a,Edge & b){ return a.w<b.w; });
    vector<Edge> mst;
   int minCost=0;
    for(int i=0;i<edges.size();i++)
    {
        Edge e = edges[i];
        int parU = find(e.u,parent);
        int parV = find(e.v,parent);
       if(parU!=parV)
       {
         union_by_rank(parU,parV,parent,rank);
         minCost+=e.w;
         mst.push_back(e);
       }

    }
     cout<<"min Cost: "<<minCost<<endl;
     for(auto e:mst)
     {
        cout<<e.u<<" : "<<e.v<<" : "<<e.w<<endl;
     }

}
int main()
{
    int V,E;
    cout<<"enter the vertices and edges"<<endl;
    cin>>V>>E;
   vector<Edge> edge(E);
   cout<<"enter the u , v and w"<<endl;
   for(int i=0;i<E;i++)
   {
      cin>>edge[i].u>>edge[i].v>>edge[i].w;
   }
   kruskals(V,edge);
    return 0;
}