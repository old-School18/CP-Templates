// Time Complexity: O(V+E)
// Memory Complexity: O(V)
// Tarjan's Algorithm for Bridge (Cut Edge) Detection
// Bridges/cut-edges: Edges whose removal increases the number of connected components in a graph
// Undirected Graphs

void dfs(vector<vector<ll>> &adj, vector<ll> &discovery, vector<ll> &low,
         vector<pair<ll, ll>> &bridges, ll u, ll parent, ll &timer)
{
    discovery[u] = low[u] = ++timer;

    for (auto &v : adj[u])
    {
        if (v == parent)
        {
            continue;
        }

        if (!discovery[v])
        {
            dfs(adj, discovery, low, bridges, v, u, timer);
            low[u] = min(low[u], low[v]);
            if (low[v] > discovery[u])
            {
                bridges.push_back({u, v});
            }
        }
        else
        {
            low[u] = min(low[u], discovery[v]);
        }
    }
    return;
}
vector<pair<ll, ll>> tarjanBridges(vector<vector<ll>> &adj, ll n)
{
    vector<pair<ll, ll>> bridges;
    vector<ll> discovery(n + 1, 0);
    vector<ll> low(n + 1, 0);
    ll timer = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!discovery[i])
        {
            dfs(adj, discovery, low, bridges, i, -1, timer);
        }
    }
    return bridges;
}
