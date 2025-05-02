#include <iostream>
#include <vector>
using namespace std;

bool hasPathHelper(int src, int dest, vector<bool> &vis, vector<vector<int>> &adj) // O(V+E)
{
    if(src==dest)
    {
        return true;
    }
    vis[src] = true;
    for (int v : adj[src])
    {
        if (!vis[v])
        {
            if (hasPathHelper(v, dest, vis, adj))
            {
                return true;
            }
        }
    }
    return false;
}
bool hasPath(vector<vector<int>> &adj, int V)
{
    vector<bool> vis(V, false);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
           if(hasPathHelper(0, 3, vis, adj))
           {
              return true;
           }
        }
    }
    return false;
}
int main()
{
    cout << "Enter the vertex and edge" << endl;
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    cout << "enter the u and v" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"hasPath: "<<hasPath(adj, V);
    return 0;
}