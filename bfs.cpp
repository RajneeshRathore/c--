#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfsHelper(int src,vector<bool> &vis,vector<vector<int>>& adj,queue<int>& q) //O(V+E)
{
   vis[src]=true;
   q.push(src);
   while(!q.empty())//V
   {
      int cur = q.front(); 
      q.pop();
      cout<<cur<<" ";
      for(int v:adj[cur]) //E
      {
        if(!vis[v])
        {
            vis[v]=true;
            q.push(v);
        }
      }
   }
}
void bfs(vector<vector<int>> &adj,int V)
{
    vector<bool> vis(V,false);
    queue<int> q;
    bfsHelper(0,vis,adj,q);
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
        adj[v].push_back(u);
    }
    bfs(adj,V);
    return 0;
}