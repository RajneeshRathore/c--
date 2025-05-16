#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void calcIndeg(vector<int>& indeg,vector<vector<int>>& adj)
{
    for(int u=0;u<indeg.size();u++)
    {
       for(int v:adj[u])
       {
         indeg[v]++;
       }
    }
}
void bfs(int V,vector<vector<int>>& adj)
{
    vector<int> indeg(V,0);
    queue<int> q;
    calcIndeg(indeg,adj);
   for(int u=0;u<V;u++)
   {
     if(indeg[u]==0)
     {
        q.push(u);
     }
   }
   while(!q.empty())
   {
      int cur = q.front();
      cout<<cur<<" ";
      q.pop();
      for(int v:adj[cur])
      {
         indeg[v]--;
         if(indeg[v]==0)
         {
            q.push(v);
         }
      }
   }
}
int main()
{
    cout<<"Enter the vertex and edge"<<endl;
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V);
    cout<<"enter the u and v"<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
       // adj[v].push_back(u);
    }
    bfs(V,adj);
    return 0;
}