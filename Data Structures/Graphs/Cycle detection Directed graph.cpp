// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Cycle detection in Directed graphs

bool dfs(vector<vector<ll>> &adj, vector<bool> &vis, vector<bool> &ancestralStk, ll u)
{
    vis[u] = true;
    ancestralStk[u] = true;
    for (auto &v : adj[u])
    {
        if (!vis[v] && dfs(adj, vis, ancestralStk, v))
            return true;
        else if (ancestralStk[v])
            return true;
    }
    ancestralStk[u] = false;
    return false;
}

bool cycleDirected(vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n + 1, false);
    vector<bool> ancestralStk(n + 1, false);
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i] && dfs(adj, vis, ancestralStk, i))
            return true;
    }
    return false;
}
