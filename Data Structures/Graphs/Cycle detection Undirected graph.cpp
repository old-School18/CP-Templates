// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Cycle detection in undirected graphs

// DFS
bool dfsRecurse(vector<vector<ll>> &adj, vector<bool> &vis, ll u, ll parent)
{
    vis[u] = true;

    for (auto &v : adj[u])
    {
        if ((vis[v] && v != parent) || (!vis[v] && dfsRecurse(adj, vis, v, u)))
        {
            return true;
        }
    }
    return false;
}

bool dfs(vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n + 1, false);
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i] && dfsRecurse(adj, vis, i, 0))
        {
            return true;
        }
    }
    return false;
}

bool cycleDetectionUndirected(vector<vector<ll>> &adj, ll n)
{
    return dfs(adj, n);
}

---------------------
// BFS
bool bfs(vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n + 1, false);
    queue<pair<ll, ll>> qe;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            qe.push({i, 0});
            vis[i] = true;
            while (!qe.empty())
            {
                auto [u, parent] = qe.front();
                qe.pop();
                for (auto &v : adj[u])
                {
                    if (vis[v] && v != parent)
                    {
                        return true;
                    }
                    if (!vis[v])
                    {
                        qe.push({v, u});
                        vis[v] = true;
                    }
                }
            }
        }
    }
    return false;
}

bool cycleDetectionUndirected(vector<vector<ll>> &adj, ll n)
{
    return bfs(adj, n);
}
