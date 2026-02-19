// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Cycle detection in Directed graphs


bool dfs(vector<vector<ll>> &adj, vector<bool> &vis, vector<bool> &ancestral_stk, ll u)
{
    vis[u] = true;
    ancestral_stk[u] = true;
    for (auto &v : adj[u])
    {
        if (!vis[v] && dfs(adj, vis, ancestral_stk, v))
            return true;
        else if (ancestral_stk[v])
            return true;
    }
    ancestral_stk[u] = false;
    return false;
}

bool cycleDirected(vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n + 1, false);
    vector<bool> ancestral_stk(n + 1, false);
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i] && dfs(adj, vis, ancestral_stk, i))
            return true;
    }
    return false;
}
